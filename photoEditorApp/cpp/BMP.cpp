#include "Bmp.h"

void BMP::ucitavanjeTridesetDva(int visina, int sirina, std::ifstream& fajl, bool okrenut)
{
	pikseli.resize(visina);
	for (int i = 0; i <visina; i++)
		pikseli[i].resize(sirina);
	for (int i = 0; i < visina; i++){
		for (int j = 0; j < sirina; j++){
			int plava = (int)fajl.get();
			int zelena = (int)fajl.get();
			int crvena = (int)fajl.get();
			int prozir = (int)fajl.get();
			if (okrenut) {
				pikseli[visina - 1 - i][j] = std::make_shared<Piksel>(crvena, zelena, plava, (int)(prozir / 2.55));
			}
			else {
				pikseli[i][j] = std::make_shared<Piksel>(crvena, zelena, plava, (int)(prozir / 2.55));
			}
		}
	}
}

void BMP::ucitavanjeDvadesetCetiri(int visina, int sirina, std::ifstream& fajl, bool okrenut)
{
	pikseli.resize(visina);
	for (int i = 0; i < visina; i++)
		pikseli[i].resize(sirina);
	for (int i = 0; i < visina; i++){
		for (int j = 0; j < sirina; j++){
			int plava = (int)fajl.get();
			int zelena = (int)fajl.get();
			int crvena = (int)fajl.get();
			if (okrenut) {
				pikseli[visina - 1 - i][j] = std::make_shared<Piksel>(crvena, zelena, plava, 100);
			}
			else{
				pikseli[i][j] = std::make_shared<Piksel>(crvena, zelena, plava, 100);
			}
		}
		fajl.seekg(sirina % 4, std::ios::cur);
	}
}

void BMP::cuvanjeHedera(std::ofstream& fajl, std::shared_ptr<Sloj> s)
{
	unsigned char pom[2]{ 'B','M' };
	fajl.write((char*)(&pom), 2 * sizeof(unsigned char));
	Heder heder = { 0 };
	heder.pomeraj = 0x7A;
	heder.velicinaFajla = heder.pomeraj
		+ s->dohvatiDodataSirina() *4 * s->dohvatiDodataVisina();
	fajl.write((char*)(&heder), sizeof(heder));
}

void BMP::cuvanjePrviInfo(std::ofstream& fajl, std::shared_ptr<Sloj> s)
{
	Info24 info24 = { 0 };
	info24.velicinaHedera = 0x6C;
	info24.sirina = s->dohvatiDodataSirina();
	info24.visina = s->dohvatiDodataVisina();
	info24.brojAviona = 1;
	info24.bitoviPoPikselu = 32;
	info24.kompresija = 3;
	info24.velicinaPodatka = 32;
	info24.pikseliHorizontalno = 2835;
	info24.pikseliVertikalno = 2835;
	info24.brojBoja = 0;
	info24.brojVaznihBoja = 0;
	fajl.write((char*)(&info24), sizeof(info24));
}

void BMP::cuvanjeDrogogDelaInfo(std::ofstream& fajl, std::shared_ptr<Sloj> s)
{
	Info32 info32 = { 0 };
	info32.pom1 = 0xFF0000;
	info32.pom2 = 0xFF00;
	info32.pom3 = 0xFF;
	info32.pom4 = 0xFF000000;
	info32.pom5 = 0x57696E20;
	info32.pom6 = 0;
	info32.pom7 = 0;
	info32.pom8 = 0;
	info32.pom9 = 0;
	info32.pom10 = 0;
	info32.pom11 = 0;
	info32.pom12 = 0;
	info32.pom13 = 0;
	info32.pom14 = 0;
	info32.pom15 = 0;
	info32.pom16 = 0;
	info32.pom17 = 0;
	fajl.write((char*)(&info32), sizeof(info32));
}

void BMP::cuvanjePiksela(std::ofstream& fajl, std::shared_ptr<Sloj> s)
{
	for (int i = s->dohvatiDodataVisina() - 1; i >= 0; i--){
		for (int j = 0; j < s->dohvatiDodataSirina(); j++){
			std::shared_ptr<Piksel> p = s->dohvatiPiskel(i, j);
			fajl.put((unsigned char)(p->dohvatiPlava()));
			fajl.put((unsigned char)(p->dohvatiZelena()));
			fajl.put((unsigned char)(p->dohvatiCrvena()));
			fajl.put((unsigned char)((int)(2.55 * p->dohvatiProzirnost())));
		}
	}
}

std::shared_ptr<Slika> BMP::otvori(std::string ime, std::string nesto1, std::string nesto2, std::string nesto3)
{
	unsigned char pom[2];
	std::ifstream fajl(ime.c_str(), std::ios::in | std::ios::binary);
	for (int i = 0; i <(int) pikseli.size(); i++)	{
		pikseli[i].clear();
	}
	pikseli.clear();
	if (fajl.fail()){
		fajl.close();
		throw GreskeBmpOtvaranje();
	}
	else
	{
		fajl.read((char*)(&pom), 2 * sizeof(unsigned char));
		if (pom[0] != 'B' || pom[1] != 'M'){
			fajl.close();
			throw GreskeBmpFormat();
		}
		else
		{
			Heder heder;
			fajl.read((char*)(&heder), sizeof(heder));
			Info24 info24;
			fajl.read((char*)(&info24), sizeof(info24));
			bool okrenut = true;
			if (info24.visina < 0){
				okrenut = false;
				info24.visina = -info24.visina;
			}
			/*if (info24.kompresija != 0) {
				throw GreskeBmpKompresija();
			}*/
			if (info24.bitoviPoPikselu == 32){
				Info32 info32;
				fajl.read((char*)(&info32), sizeof(info32));
				ucitavanjeTridesetDva(info24.visina, info24.sirina, fajl, okrenut);
			}
			else {
				if (info24.bitoviPoPikselu != 24)
					throw GreskeBmpFormat();
				fajl.seekg(heder.pomeraj);
				ucitavanjeDvadesetCetiri(info24.visina, info24.sirina, fajl, okrenut);
			}
			int levo = atoi(nesto1.c_str()), gore = atoi(nesto2.c_str()), prozirnost = atoi(nesto3.c_str());
			/*if (!nesto) {
				int pom = 0;
				fajl.close();
				std::cout << "Unesite da li zelite da dodate parametre slici(gde ce se sloj nalaziti)1 za da \n";
				std::cin >> pom;
				
				if (pom == 1) {
					std::cout << "Unesite  levo , gore , prozirnost\n";
					std::cin >> levo >> gore >> prozirnost;
				}
			}*/
			
			fajl.close();
			return std::make_shared<Slika>(ime,std::move(pikseli), info24.visina, info24.sirina, levo, gore, prozirnost);
		}
	}
}

void BMP::sacuvaj(std::string ime, std::shared_ptr<Sloj> s)
{
	std::ofstream fajl(ime.c_str(), std::ios::out | std::ios::binary);
	if (fajl.fail()){
		fajl.close();
		throw GreskeBmpCuvanje();
	}
	else
	{
		cuvanjeHedera(fajl, s);
		cuvanjePrviInfo(fajl, s);
		cuvanjeDrogogDelaInfo(fajl, s);
		cuvanjePiksela(fajl, s);
		fajl.close();
	}
}
