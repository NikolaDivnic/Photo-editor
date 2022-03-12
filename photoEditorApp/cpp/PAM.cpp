#include "PAM.h"

void PAM::ucitavanjeHedera(std::ifstream& fajl , Heder * heder)
{
	fajl.read((char*)(&heder->sirinaOznaka), 5 * sizeof(unsigned char));
	fajl.get();
	unsigned char c = fajl.get();
	int i = 0;
	while (c != '\n') {
		i = i * 10 + c - 48;
		c = fajl.get();
	}
	heder->sirina = i;
	fajl.read((char*)(&heder->visinaOznaka), 6 * sizeof(unsigned char));
	fajl.get();
	c = fajl.get();
	i = 0;
	while (c != '\n') {
		i = i * 10 + c - 48;
		c = fajl.get();
	}
	heder->visina = i;
	fajl.read((char*)(&heder->dubinaOznaka), 5 * sizeof(unsigned char));
	fajl.get();
	c = fajl.get();
	i = 0;
	while (c != '\n') {
		i = i * 10 + c - 48;
		c = fajl.get();
	}
	heder->dubina = i;

	fajl.read((char*)(&heder->maxOznaka), 6 * sizeof(unsigned char));
	fajl.get();
	c = fajl.get();
	i = 0;
	while (c != '\n') {
		i = i * 10 + c - 48;
		c = fajl.get();
	}
	heder->max = i;

	fajl.read((char*)(&heder->tipOznaka), 8 * sizeof(unsigned char));
	fajl.get();
	i = 0;
	do {
		c = fajl.get();
		heder->tip[i++] = c;
	} while (c != '\n');
	fajl.read((char*)(&heder->kraj), 6 * sizeof(unsigned char));
	fajl.get();
	if (heder->dubina < 0 || heder->sirina < 0 || heder->max < 0) {
		fajl.close();
		throw GreskaPAMformat();
	}

	if (heder->kraj[0] != 'E' || heder->kraj[1] != 'N' || heder->kraj[2] != 'D' || heder->kraj[3] != 'H' || heder->kraj[4] != 'D' || heder->kraj[5] != 'R') {
		fajl.close();
		throw GreskaPAMformat();
	}

	pikseli.resize(heder->visina);
	for (int i = 0; i < heder->visina; i++)
		pikseli[i].resize(heder->sirina);
}

void PAM::citanjeRGB(std::ifstream& fajl, int visina, int sirina)
{
	for (int i = 0; i < visina; i++)	{
		for (int j = 0; j < sirina; j++){
			int crvena = (int)fajl.get();
			int zelena = (int)fajl.get();
			int plava = (int)fajl.get();
			pikseli[i][j] = std::make_shared<Piksel>(crvena, zelena, plava, 100);
		}
	}
}

void PAM::citanjeRGB_ALPHA(std::ifstream& fajl, int visina, int sirina)
{
	for (int i = 0; i < visina; i++) {
		for (int j = 0; j < sirina; j++) {
			int crvena = (int)fajl.get();
			int zelena = (int)fajl.get();
			int plava = (int)fajl.get();
			int prozir = (int)fajl.get();
			pikseli[i][j] = std::make_shared<Piksel>(crvena, zelena, plava, (int)(prozir / 2.55));
		}
	}
}

std::shared_ptr<Slika> PAM::otvori(std::string ime, std::string nesto1, std::string nesto2, std::string nesto3)
{
	Heder heder;
	unsigned char pom[3];
	std::ifstream fajl(ime.c_str(), std::ios::in | std::ios::binary);
	for (int i = 0; i < (int)pikseli.size(); i++) {
		pikseli[i].clear();
	}
	pikseli.clear();
	if (fajl.fail()) {
		fajl.close();
		throw GreskePAMOtvaranje();
	}
	else {
		fajl.read((char*)(&pom), 3 * sizeof(unsigned char));
		if (pom[0] != 'P' || pom[1] != '7') {
			fajl.close();
			throw GreskaPAMformat();
		}
		ucitavanjeHedera(fajl,&heder);	
		if (heder.tip[0] == 'R' && heder.tip[1] == 'G' && heder.tip[2] == 'B' && heder.tip[3] == '\n') {
			citanjeRGB(fajl , heder.visina , heder.sirina);
		}
		else {
			if (heder.tip[0] == 'R' && heder.tip[1] == 'G' && heder.tip[2] == 'B' && heder.tip[3] == '_' && heder.tip[4] == 'A' && heder.tip[5] == 'L'
				&& heder.tip[6] == 'P' && heder.tip[7] == 'H' && heder.tip[8] == 'A') {
				citanjeRGB_ALPHA(fajl, heder.visina, heder.sirina);
			}
			else {
				fajl.close();
				throw NijePodrezanTajPamFormat();
			}
		}
		int pom = 0;
		int levo = atoi(nesto1.c_str()), gore = atoi(nesto2.c_str()), prozirnost = atoi(nesto3.c_str());
		fajl.close();
		return std::make_shared<Slika>(ime, std::move(pikseli), heder.visina, heder.sirina, levo, gore, prozirnost);
	}
	fajl.close();
	return std::make_shared<Slika>(ime, std::move(pikseli), heder.visina, heder.sirina);
}

void PAM::sacuvaj(std::string ime, std::shared_ptr<Sloj> s)
{
	std::ofstream fajl(ime.c_str(), std::ios::out | std::ios::binary);
	if (fajl.fail()) {
		fajl.close();
		throw GreskaPAMformat();
	}
	else
	{
		fajl << "P7\nWIDTH " << s->dohvatiDodataSirina() << "\nHEIGHT " << s->dohvatiDodataVisina() << "\nDEPTH " << 4 << "\nMAXVAL "
			<< 255 << "\nTUPLTYPE RGB_ALPHA\nENDHDR\n";
		for (int i = 0; i < s->dohvatiDodataVisina(); i++) {
			for (int j = 0; j < s->dohvatiDodataSirina(); j++) {
				std::shared_ptr<Piksel> p = s->dohvatiPiskel(i, j);
				fajl.put((unsigned char)(p->dohvatiCrvena()));
				fajl.put((unsigned char)(p->dohvatiZelena()));
				fajl.put((unsigned char)(p->dohvatiPlava()));
				fajl.put((unsigned char)((int)(2.55 * p->dohvatiProzirnost())));
			}
		}
	}
	fajl.close();
}
