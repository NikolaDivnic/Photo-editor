#include"Slika.h"
#include"BMP.h"
#include "OsnovneOperacije.h"
#include"SlozenaOperacija.h"
#include"PAM.h"
#include"MojFormat.h"

std::shared_ptr<Slika>  otvaranjeMetode() {
	MojFormat mf;
	PAM pam;
	BMP bm;

	int pom2 = 0;
	std::cout << "Unesite koji format zelite da ucitate\n"
		<< "1 BMP format\n"
		<< "2 PAM format\n"
		<< "3 moj format\n";
	std::string putanja;
	std::cin >> pom2;
	std::cout << "Unesite putanju do fajla\n";
	std::shared_ptr<Slika>s2;
	std::cin >> putanja;
	switch (pom2)
	{
	case 1:  s2 = bm.otvori(putanja, "0", "0", "100"); break;
	case 2: s2 = pam.otvori(putanja, "0", "0", "100"); break;
	case 3: s2 = mf.otvori(putanja, "0", "0", "100"); break;
	default:
		throw Granice();
	}
	return s2;
}
std::shared_ptr<Slika>  otvaranjeMetode(std::string ime) {
	MojFormat mf;
	PAM pam;
	BMP bm;
	std::shared_ptr<Slika>s2;
	if (!std::strncmp(&ime[ime.size() - 4], ".bmp", 4))
	{
		s2 = bm.otvori(ime, "0", "0","100");
		std::ofstream fajl("selekcijeZaJavu.txt", std::ios::out);
		fajl << "nema" << "\n";
		fajl.close();
	}
	if (!std::strncmp(&ime[ime.size() - 4], ".pam", 4)) {
		s2 = pam.otvori(ime, "0", "0", "100");
		std::ofstream fajl("selekcijeZaJavu.txt", std::ios::out);
		fajl << "nema" << "\n";
		fajl.close();
	}
	if (!std::strncmp(&ime[ime.size() - 4], ".xml", 4)) {
		s2 = mf.otvori(ime, "0", "0", "100");
		std::ofstream fajl("selekcijeZaJavu.txt", std::ios::out);
		fajl << s2->brojSelekcija()<<"\n";
		for (int i = 0; i < s2->brojSelekcija(); i++) {
			fajl << s2->dohvatiSelekciju(i)->dohvatiIme() << "\n";
			fajl << s2->dohvatiSelekciju(i)->dohvatiAktivna() << "\n";
			fajl << s2->dohvatiSelekciju(i)->dohvatiBrojPravougaonika()<< "\n";
			for (int j = 0; j < s2->dohvatiSelekciju(i)->dohvatiBrojPravougaonika(); j++) {
				fajl << s2->dohvatiSelekciju(i)->dohvatiPravougaonik(j)->dohvatiVisinu() << "\n";
				fajl << s2->dohvatiSelekciju(i)->dohvatiPravougaonik(j)->dohvatiSirinu() << "\n";
				fajl << s2->dohvatiSelekciju(i)->dohvatiPravougaonik(j)->dohvatiGore() << "\n";
				fajl << s2->dohvatiSelekciju(i)->dohvatiPravougaonik(j)->dohvatiLevo() << "\n";
			}
		}
		fajl.close();
	}
	return s2;
}
void cuvanjeSlike(std::shared_ptr<Slika> s ,std::string ime) {
	MojFormat mf;
	PAM pam;
	BMP bm;
	if (!std::strncmp(&ime[ime.size() - 4], ".bmp", 4))bm.sacuvaj(ime,s->racunajSliku());
	if (!std::strncmp(&ime[ime.size() - 4], ".pam", 4))pam.sacuvaj(ime, s->racunajSliku());
	if (!std::strncmp(&ime[ime.size() - 4], ".xml", 4))mf.sacuvaj(ime , s);
}
void cuvanjeSlike(std::shared_ptr<Slika> s) {
	MojFormat mf;
	PAM pam;
	BMP bm;
	int pom2 = 0;
	std::cout << "Unesite koji format zelite da ucitate\n"
		<< "1 BMP format\n"
		<< "2 PAM format\n"
		<< "3 moj format\n";
	std::cin >> pom2;
	std::string putanja;
	std::cout << "Unesite putanju fajla\n";
	std::cin >> putanja;
	switch (pom2)
	{
	case 1: bm.sacuvaj(putanja, s->racunajSliku()); break;
	case 2: pam.sacuvaj(putanja, s->racunajSliku()); break;
	case 3: mf.sacuvaj(putanja, s); break;
	default:
		throw Granice();
	}
	//bm.sacuvaj("C:\\Users\\Nikola\\Desktop\\slika.bmp", s->racunajSliku());
}
void dodajSloj(std::shared_ptr<Slika> s) {
	/*MojFormat mf;
	PAM pam;
	BMP bm;
	int pom2 = 0;
	std::shared_ptr<Slika> s2;
	std::cout << "Unesite koji format zelite da ucitate\n"
		<< "1 BMP format\n"
		<< "2 PAM format\n"
		<< "3 moj format\n";
	std::string putanja;
	std::cin >> pom2;
	std::cout << "Unesite putanju fajla\n";
	std::cin >> putanja;
	switch (pom2)
	{
	case 1: s2 = bm.otvori(putanja, false); break;
	case 2: s2 = pam.otvori(putanja, false); break;
	case 3: s2 = mf.otvori(putanja, false); break;
	default:
		throw Granice();
	}
	s->dodajSloj(s2->dohvatiSloj(0));*/
}
void dodajSloj(std::shared_ptr<Slika> s,  std::string drugi
	, std::string levo, std::string gore, std::string prozi) {
	MojFormat mf;
	PAM pam;
	BMP bm;
	int pom2 = 0;
	std::shared_ptr<Slika> s2;

	if (!std::strncmp(&drugi[drugi.size() - 4], ".bmp", 4))s2 = bm.otvori(drugi, levo, gore, prozi);
	else if (!std::strncmp(&drugi[drugi.size() - 4], ".pam", 4))s2 = pam.otvori(drugi, levo, gore, prozi);
	else if(!std::strncmp(&drugi[drugi.size() - 4], ".xml", 4))s2 = mf.otvori(drugi, levo, gore, prozi);
	else throw Granice();
	s->dodajSloj(s2->dohvatiSloj(0));
}
void dodavanjeSelekcije(std::shared_ptr<Slika> s) {
	std::cout << "Da bi se dodala selekcija potrebno je da se prosledi\n"
		<< "niz pravougaonika ,tako da je potrebno napraviti pravouganike\n";
	std::vector<std::shared_ptr<Pravougaonik>> pravougaonici;
	while (true) {
		int i, visina, sirina, gore, levo;
		std::cout << "Unesite da li zelite da dodajete pravougaonike(0 ako ne zelite)\n";
		std::cin >> i;
		if (i == 0)break;
		std::cout << "Unesite parametre pravougaonika visina, sirina, gore, levo\n";
		std::cin >> visina >> sirina >> gore >> levo;
		pravougaonici.push_back(std::make_shared<Pravougaonik>(visina, sirina, gore, levo));
	}
	std::cout << "Unesite ime\n";
	std::string ime;

	std::cin >> ime;
	s->dodajSelekciju(std::make_shared<Selekcija>(pravougaonici, ime, true));
}
void radSaPravougaonikom(std::shared_ptr<Selekcija> selekcija) {
	int j;
	std::cin >> j;
	std::shared_ptr<Pravougaonik> p = selekcija->dohvatiPravougaonik(j);
	bool fleg = true;
	while (fleg) {
		std::cout << "Unesite redni broj stavke za rad sa przvougaonikom\n"
			<< "1 dohvati visinu\n"
			<< "2 dohvati sirinu\n"
			<< "3 dohvati gore\n"
			<< "4 dohvati levo\n";
		int i;
		std::cin >> i;
		switch (i)
		{
		case 0:fleg = false; break;
		case 1:std::cout << p->dohvatiVisinu(); break;
		case 2:std::cout << p->dohvatiSirinu(); break;
		case 3:std::cout << p->dohvatiGore(); break;
		case 4:std::cout << p->dohvatiLevo(); break;
		default:
			break;
		}
	}
}
void radSaSelekcijom(std::shared_ptr<Selekcija> selekcija) {
	bool fleg = true;
	while (fleg) {
		std::cout << "\nUnesite redni broj stavke za rad sa selekcijom\n"
			<< "0 za prekid rada sa selekcijom\n"
			<< "1 dohvatanje imena\n"
			<< "2 da li je aktivna selekcija\n"
			<< "3 dohvati broj pravougaonika\n"
			<< "4 dohvati pravougaonik\n"
			<< "5 postavi aktivnost\n";
		int i;
		std::cin >> i;
		switch (i)
		{
		case 0:fleg = false; break;
		case 1:std::cout << selekcija->dohvatiIme(); break;
		case 2:std::cout << selekcija->dohvatiAktivna(); break;
		case 3:std::cout << selekcija->dohvatiBrojPravougaonika(); break;
		case 4:
			radSaPravougaonikom(selekcija); break;
		case 5:
			int j;
			std::cin >> j;
			selekcija->postaviAktivnost(j); break;
		default:
			break;
		}
	}

}
void izvrsiOperaciju(std::shared_ptr<Slika> s) {
	std::cout << "\nUnesite redni broj operacije koju zelite da izvrsite\n";
	int i;
	std::cin >> i;
	s->dohvatiOperaciju(i)->izvrsi(*s);
}
void izvrsiOperaciju(std::shared_ptr<Slika> s , int i) {

	s->dohvatiOperaciju(i)->izvrsi(*s);
}
void dohvatanjePiksela(std::shared_ptr<Sloj> sloj) {
	std::cout << "Unesite piksel sloja(kordinate u matrici piksela sloja) koji zelite da dohvatite\n";
	int i, j;
	bool fleg = true;
	std::cin >> i >> j;
	if (sloj->daLiJePikselUTomSloju(i, j)) {
		std::shared_ptr<Piksel> p = sloj->dohvatiPiskel(i, j);
		while (fleg) {
			std::cout << "Unesite sta zelite da radite sa pikselom\n"
				<< " 0 za prekid rada sa pikselom\n"
				<< "1 dohvati crvenu\n"
				<< "2 dohvati zelenu\n"
				<< "3 dohvati plavu\n"
				<< "4 dohvati prozirnost\n"
				<< "5 postavi crvenu\n"
				<< "6 postavi zelenu\n"
				<< "7 postavi plavu\n"
				<< "8 postavi prozirnost\n"
				<< "9 postavi sve tri boje\n";
			std::cin >> i;
			switch (i)
			{
			case 0:fleg = false; break;
			case 1:std::cout << p->dohvatiCrvena(); break;
			case 2:std::cout << p->dohvatiZelena(); break;
			case 3:std::cout << p->dohvatiPlava(); break;
			case 4:std::cout << p->dohvatiProzirnost(); break;
			case 5:
				std::cout << "Unesite vrednost boje\n";
				std::cin >> j;
				p->postaviCrvenu(j); break;
			case 6:
				std::cout << "Unesite vrednost boje\n";
				std::cin >> j;
				p->postaviZelenu(j); break;
			case 7:
				std::cout << "Unesite vrednost boje\n";
				std::cin >> j;
				p->postaviPlavu(j); break;
			case 8:
				std::cout << "Unesite vrednost prozirnosti\n";
				std::cin >> j;
				p->postaviProzirnost(j); break;
			case 9:
				std::cout << "Unesite vrednost boje\n";
				int l, jj, k;
				std::cin >> l >> jj >> k;
				p->postaviBoju(l, jj, k); break;
			default:
				break;
			}
		}
	}
	else {
		std::cout << "\nTaj piksel ne pripada tom sloju\n";
		return;
	}


}
void radSaSlojem(std::shared_ptr<Slika> s) {
	std::cout << "Unesite redni broj sloja sa kojim zelite da radite\n";
	int i;
	std::cin >> i;
	bool fleg = true;
	std::shared_ptr<Sloj> sloj = s->dohvatiSloj(i);
	while (fleg) {
		std::cout << "\nUnesite redni broj stavki za rad sa slojem\n"
			<< "0 za prekid obrade nad slojem\n"
			<< "1 dohvatanje putanje\n"
			<< "2 dohvati aktivnost\n"
			<< "3 dohvati prozirnost\n"
			<< "4 dohvati vidljivost\n"
			<< "5 postavi aktivnost\n"
			<< "6 postavi prozirnost\n"
			<< "7 postavi vidljivost\n"
			<< "8 dohvati visinu(bez praznih piksela)\n"
			<< "9 dohvati sirinu(bez praznih piksela)\n"
			<< "10 dohvati gore\n"
			<< "11 dohvati levo\n"
			<< "12 dohvati dodatu visinu (visinu sa dodatim praznim pikselima)\n"
			<< "13 dohvati dodatu sirinu (sirinu sa dodatim praznim pikselima)\n"
			<< "14 dohvati piksel\n";

		std::cin >> i;
		switch (i)
		{
		case 0:fleg = false; break;
		case 1:std::cout << sloj->dohvatiPutanju(); break;
		case 2:std::cout << sloj->dohvatiAktivna(); break;
		case 3:std::cout << sloj->dohvatiProzirnost(); break;
		case 4:std::cout << sloj->dohvatiVidljivost(); break;
		case 5:
			std::cout << "Unesite aktivnost\n";
			int ii;
			std::cin >> ii;
			sloj->postaviAktivnost((bool)ii); break;
		case 6:
			std::cout << "Unesite prozirnost\n";
			std::cin >> ii;
			sloj->postaviProzirnost(ii); break;
		case 7:
			std::cout << "Unesite vidljivost\n";
			int iii;
			std::cin >> iii;
			sloj->postaviVidljivost((bool)iii); break;
		case 8:std::cout << sloj->dohvatiVisinu(); break;
		case 9:std::cout << sloj->dohvatiSirinu(); break;
		case 10:std::cout << sloj->dohvatiGore(); break;
		case 11:std::cout << sloj->dohvatiLevo(); break;
		case 12:std::cout << sloj->dohvatiDodataVisina(); break;
		case 13:std::cout << sloj->dohvatiDodataSirina(); break;
		case 14:dohvatanjePiksela(sloj); break;
		default:
			break;
		}
	}



}
std::shared_ptr<Slika> pravljenjeSloja(int visina , int sirina) {

	std::shared_ptr<Slika> s2 = std::make_shared<Slika>(std::make_shared <Sloj>(visina, sirina, 100));
	return s2;
}
std::shared_ptr<Slika> pravljenjeSloja() {
	int visina, sirina;

	std::cout << "Unesite dimenzije sloja\n";
	std::cin >> visina >> sirina;
	std::shared_ptr<Slika> s2 = std::make_shared<Slika>(std::make_shared <Sloj>(visina, sirina, 100));
	return s2;
}
void dodavanjeOsnovneOperacije(std::shared_ptr<Slika> s) {
	int redniBrojOperacije, konstanta;
	std::string boja;
	std::cout << "Unesite redni broj konstante koju zelite da dodate\n "
		<< "0 sabiranje sa konstantom\n"
		<< "1 oduzimanje sa konstantom\n"
		<< "2 inverzno oduzimanje\n"
		<< "3 mnozenje konstantom\n"
		<< "4 deljnje konstantom\n"
		<< "5 inverzno deljenje\n"
		<< "6 stepenovanje(power)\n"
		<< "7 logaritmovanje\n"
		<< "8 apsolutna vrednostn\n"
		<< "9 minimum\n"
		<< "10 maksimum\n"
		<< "11 negacija boje\n"
		<< "12 pretvaranje u sivu\n"
		<< "13 pretvaranje u crno- belu\n"
		<< "14 medijana boje piksela sa okolnim piskelima\n";
	std::cin >> redniBrojOperacije;
	if (redniBrojOperacije < 11 && redniBrojOperacije>-1) {
		std::cout << "Unesite boju na koju se odnosi(crvena,zelena,plava,sve) i konstantu\n";
		std::cin >> boja >> konstanta;
		s->dodajOperaciju(std::make_shared<OsnovneOperacije>((OsnovneOperacije::OPERACIJE)redniBrojOperacije, boja, konstanta));
	}
	else {
		if (redniBrojOperacije < 15 && redniBrojOperacije>10) {
			std::cout << "Unesite boju na koju se odnosi(crvena, zelena, plava)\n";
			std::cin >> boja;
			s->dodajOperaciju(std::make_shared<OsnovneOperacije>((OsnovneOperacije::OPERACIJE)redniBrojOperacije, boja));
		}
	}
}
void dodavanjeOsnovneOperacije(std::shared_ptr<SlozenaOperacija> s) {
	int redniBrojOperacije, konstanta;
	std::string boja;
	std::cout << "Unesite redni broj konstante koju zelite da dodate\n "
		<< "0 sabiranje sa konstantom\n"
		<< "1 oduzimanje sa konstantom\n"
		<< "2 inverzno oduzimanje\n"
		<< "3 mnozenje konstantom\n"
		<< "4 deljnje konstantom\n"
		<< "5 inverzno deljenje\n"
		<< "6 stepenovanje(power)\n"
		<< "7 logaritmovanje\n"
		<< "8 apsolutna vrednostn\n"
		<< "9 minimum\n"
		<< "10 maksimum\n"
		<< "11 negacija boje\n"
		<< "12 pretvaranje u sivu\n"
		<< "13 pretvaranje u crno- belu\n"
		<< "14 medijana boje piksela sa okolnim piskelima\n";
	std::cin >> redniBrojOperacije;
	if (redniBrojOperacije < 11 && redniBrojOperacije>-1) {
		std::cout << "Unesite boju na koju se odnosi(crvena,zelena,plava,sve) i konstantu\n";
		std::cin >> boja >> konstanta;
		s->dodajOperaciju(std::make_shared<OsnovneOperacije>((OsnovneOperacije::OPERACIJE)redniBrojOperacije, boja, konstanta));
	}
	else {
		if (redniBrojOperacije < 15 && redniBrojOperacije>10) {
			std::cout << "Unesite boju na koju se odnosi(crvena, zelena, plava,sve)\n";
			std::cin >> boja;
			s->dodajOperaciju(std::make_shared<OsnovneOperacije>((OsnovneOperacije::OPERACIJE)redniBrojOperacije, boja));
		}
	}
}
void dodavanjeIzvedeneOperacije(std::shared_ptr<SlozenaOperacija> s) {
	std::shared_ptr<SlozenaOperacija> slozena = std::make_shared<SlozenaOperacija>();;
	int i;
	while (true) {
		std::cout << "Unesite 0 ako zelite da prekinete sa dodavanjem operacij\n"
			<< "1 za dodavanje osnovne operacije\n"
			<< "2 za dodavanje izvedene operacije\n";
		std::cin >> i;
		if (i == 0)break;
		if (i == 1)dodavanjeOsnovneOperacije(slozena);
		if (i == 2)dodavanjeIzvedeneOperacije(slozena);
	}
	if (slozena->dohvatiBrojOperacija())s->dodajOperaciju(slozena);
}
void dodavanjeIzvedeneOperacije(std::shared_ptr<Slika> s) {
	std::shared_ptr<SlozenaOperacija> slozena = std::make_shared<SlozenaOperacija>();
	int i;
	while (true) {
		std::cout << "Unesite 0 ako zelite da prekinete sa dodavanjem operacij\n"
			<< "1 za dodavanje osnovne operacije\n"
			<< "2 za dodavanje izvedene operacije\n";
		std::cin >> i;
		if (i == 0)break;
		if (i == 1)dodavanjeOsnovneOperacije(slozena);
		if (i == 2)dodavanjeIzvedeneOperacije(slozena);
	}
	if (slozena->dohvatiBrojOperacija())s->dodajOperaciju(slozena);
}
void dodajOperaciju(std::shared_ptr<Slika> s) {
	int i;
	std::cout << "Ako zelite osnovnu operaciju da dodate napisite 1 ,za izvedenu 0\n";
	std::cin >> i;
	if (i == 1) {
		dodavanjeOsnovneOperacije(s);
	}
	else {
		if (i == 0) {
			dodavanjeIzvedeneOperacije(s);
		}
	}
}
void cuvanjeKompozitneUFajl(std::shared_ptr<Slika> s) {
	for (int i = 0; i < s->brojOperacija(); i++) {
		if (s->dohvatiOperaciju(i)->vrsta() == 's')
		{
			std::string putanja;
			std::cout << "Unesite putanju fajla (bez .fun)\n";
			std::cin >> putanja;
			std::ofstream fajl((putanja + ".fun").c_str(), std::ios::out);
			if (fajl.fail()) {
				fajl.close();
				throw GreskeMojCuvanje();
			}
			s->dohvatiOperaciju(i)->ispisiUFormat(fajl);
		}
	}
}
void cuvanjeKompozitneUFajl(std::shared_ptr<Slika> s , std::string putanja) {
	for (int i = 0; i < s->brojOperacija(); i++) {
		if (s->dohvatiOperaciju(i)->vrsta() == 's')
		{
	
			std::ofstream fajl((putanja ).c_str(), std::ios::out);
			if (fajl.fail()) {
				fajl.close();
				throw GreskeMojCuvanje();
			}
			s->dohvatiOperaciju(i)->ispisiUFormat(fajl);
		}
	}
}
std::shared_ptr<OsnovneOperacije> citajOsnovnuOperaciju(std::ifstream& fajl)
{
	std::string boja, linija;
	int operacija, konstanta;
	std::getline(fajl, linija);
	linija.erase(linija.begin(), linija.begin() + 12);
	linija.erase(linija.end() - 13, linija.end());
	operacija = std::stoi(linija);
	std::getline(fajl, linija);
	linija.erase(linija.begin(), linija.begin() + 7);
	linija.erase(linija.end() - 8, linija.end());
	boja = linija;
	std::getline(fajl, linija);
	linija.erase(linija.begin(), linija.begin() + 12);
	linija.erase(linija.end() - 13, linija.end());
	konstanta = std::stoi(linija);
	return  std::make_shared<OsnovneOperacije>((OsnovneOperacije::OPERACIJE)operacija, boja, konstanta);
}
std::shared_ptr<SlozenaOperacija> citajSlozenuOperaciju(std::ifstream& fajl)
{
	std::string linija;
	int broj;
	std::shared_ptr<SlozenaOperacija> slozena = std::make_shared<SlozenaOperacija>();
	std::getline(fajl, linija);
	linija.erase(linija.begin(), linija.begin() + 15);
	linija.erase(linija.end() - 17, linija.end());
	broj = std::stoi(linija);
	for (int i = 0; i < broj; ) {
		std::getline(fajl, linija);
		if (linija.find("<osnovnaOperacija>") != std::string::npos) {
			slozena->dodajOperaciju(citajOsnovnuOperaciju(fajl)); i++;
		}
		if (linija.find("<slozenaOperacija>") != std::string::npos) {
			slozena->dodajOperaciju(citajSlozenuOperaciju(fajl)); i++;
		}
	}
	return slozena;
}

void citajKompozitnu(std::shared_ptr<Slika> s) {
	std::string ime;
	std::cout << "\nUnesite ime fajla kog zelite da otvorite\n";
	std::cin >> ime;
	std::ifstream fajl(ime.c_str(), std::ios::in | std::ios::binary);
	if (fajl.fail()) {
		fajl.close();
		throw GreskaMojOtvaranje();
	}
	else {
		bool prviSloj = true;
		std::string linija;
		while (std::getline(fajl, linija))
		{
			if (linija.find("<slozenaOperacija>") != std::string::npos) {
				s->dodajOperaciju(citajSlozenuOperaciju(fajl));
			}
		}
	}
}
void citajKompozitnu(std::shared_ptr<Slika> s , std::string ime ) {

	std::ifstream fajl(ime.c_str(), std::ios::in | std::ios::binary);
	if (fajl.fail()) {
		fajl.close();
		throw GreskaMojOtvaranje();
	}
	else {
		bool prviSloj = true;
		std::string linija;
		while (std::getline(fajl, linija))
		{
			if (linija.find("<slozenaOperacija>") != std::string::npos) {
				s->dodajOperaciju(citajSlozenuOperaciju(fajl));
			}
		}
	}
}
void citajKompozitnu(std::shared_ptr<Slika> s ,std::string ime ,bool t) {

	std::ifstream fajl(ime.c_str(), std::ios::in | std::ios::binary);
	if (fajl.fail()) {
		fajl.close();
		throw GreskaMojOtvaranje();
	}
	else {
		bool prviSloj = true;
		std::string linija;
		while (std::getline(fajl, linija))
		{
			if (linija.find("<slozenaOperacija>") != std::string::npos) {
				s->dodajOperaciju(citajSlozenuOperaciju(fajl));
			}
		}
	}
}
void proveraAktivnosti(std::shared_ptr<Slika> s) {

	std::ofstream fajl("aktivna.txt", std::ios::out);
	if (fajl.fail()) {
		fajl.close();
		throw GreskeMojCuvanje();
	}
	for (int i = 0; i < s->brojSlojeva(); i++) {		
		fajl <<(int)( s->dohvatiSloj(i)->dohvatiAktivna())<<"\n";
	}
	fajl.close();
}
void dodavanjeSelekcije(std::shared_ptr<Slika> s , bool t) {
	MojFormat mf;
	std::ifstream fajl("selekcija.txt", std::ios::in | std::ios::binary);
	if (fajl.fail()) {
		fajl.close();
		throw GreskaMojOtvaranje();
	}
	std::string linija;
	std::getline(fajl, linija);
	s->dodajSelekciju(mf.citajSelukciju(fajl));
	fajl.close();
}
void sacuvajSveSelekcijeFajl(std::shared_ptr<Slika> s) {
	std::ofstream fajl("selekcijeSve.txt", std::ios::out);
	for (int i = 0; i < s->brojSelekcija(); i++) {
		fajl << s->dohvatiSelekciju(i)->dohvatiIme()<<"\n";
	}
	fajl.close();
}
void sacuvajSveAktivneSelekcije(std::shared_ptr<Slika> s) {
	std::ofstream fajl("selekcijeAktivne.txt", std::ios::out);
	for (int i = 0; i < s->brojSelekcija(); i++) {
		if (s->dohvatiSelekciju(i)->dohvatiAktivna())
			fajl << s->dohvatiSelekciju(i)->dohvatiIme() << "\n";
	}
	fajl.close();
}

int main(int argc, char** argv) {

	BMP bm;
	std::shared_ptr<Slika> s;
	std::shared_ptr<Selekcija> selekcija;
	std::shared_ptr<Operacija> operacija;
	std::string ime;
	/*if (argc < 3) {
		int pp = 0;
		bool fleg = false, ucitaniPodaci = false;
		while (true) {
			try {

				std::cout << "\nUnesite broj za stavku koju zelite da unesete\n"
					<< "0 za izlaz\n"
					<< "1 Citanje formata\n"
					<< "2 Cuvanje formata\n"
					<< "3 Dodaj sloj\n"
					<< "4 Broj slojeva\n"
					<< "5 Broj selekcija\n"
					<< "6 Brisanje sloja\n"
					<< "7 dohvatanje sloja i rad sa njim\n"
					<< "8 da li ima aktivnih selekcija na slici\n"
					<< "9 dohvatanje aktivne selekcije\n"
					<< "10 dohvatanje selekcije po imenu\n"
					<< "11 dohvatanje selekcije po rednom broju\n"
					<< "12 bojenje selekcije zadatog imena\n"
					<< "13 brisanje selekcije zadatog imena\n"
					<< "14 dodavanje selekcije\n"
					<< "15 pravljenje sloja bez slike\n"
					<< "16 dodaj operaciju\n"
					<< "17 broj operacija\n"
					<< "18 ispisi kompozitne u fajl sa ekstenzijom .fun\n"
					<< "19 citaj kompozitnu iz fajla\n"
					<< "20 izvrsi operaciju\n";
				int pom = 0;
				std::cin >> pom;
				switch (pom)
				{
				case 0:

					if (fleg) {
						std::cout << "Potvrdite Vas izlazak pritiskom na 0 bez cuvanja."
							<< "\nNije sacuvana izmena pritisnite 1 da je sacuvate\n";
						std::cin >> pp;
						if (pp == 1) {
							cuvanjeSlike(s);
							exit(1);
						}
					}
					else {
						std::cout << "Potvdite Vas izlazak time sto cete pritisnuti 0\n";
						std::cin >> pp;
					}
					if (pp == 0) {
						exit(1);
					}
					break;
				case 1:
					if (ucitaniPodaci) {
						std::cout << "\n\nVec ste ucitali sliku\n\n";
					}
					else { s = otvaranjeMetode(); fleg = true; ucitaniPodaci = true; }
					break;
				case 2:
					if (ucitaniPodaci) {
						cuvanjeSlike(s);
						fleg = false;
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					}
					
					break;
				case 3:
					if (ucitaniPodaci) {
						dodajSloj(s); fleg = true;
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					}
					break;
				case 4:
					if (ucitaniPodaci) {
						std::cout << s->brojSlojeva();
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					}
					break;
				case 5:
					if (ucitaniPodaci) {
						std::cout << s->brojSelekcija();
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					}
					break;
				case 6:
					if (ucitaniPodaci) {
						std::cout << "Unesite redni broj sloja koji zelite da obrisete\n";
						int i;
						std::cin >> i;
						s->obrisiSloj(i); fleg = true;
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					}
					break;
				case 7:
					if (ucitaniPodaci) {
						radSaSlojem(s); fleg = true;
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					}
					break;
				case 8:
					if (ucitaniPodaci) {
						std::cout << s->imaAktivnaSelekcija();
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					} break;
				case 9:
					if (ucitaniPodaci) {
						selekcija = s->dohvatiAktivnuSelekciju();
						radSaSelekcijom(selekcija); fleg = true;
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					}
					break;
				case 10:
					if (ucitaniPodaci) {
						std::cout << "Unesite ime selekcije\n";
						std::cin >> ime;
						selekcija = s->dohvatiSelekcijuPoImenu(ime);
						radSaSelekcijom(selekcija); fleg = true;
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					}
					break;
				case 11:
					if (ucitaniPodaci) {
						std::cout << "Unesite redni broj selekcije\n";
						int j;
						std::cin >> j;
						selekcija = s->dohvatiSelekciju(j);
						radSaSelekcijom(selekcija); fleg = true;
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					}
					break;
				case 12:
					if (ucitaniPodaci) {
						std::cout << "Unesite ime selekcije i boje\n";
						int crvena, zelena, plava;
						std::cin >> ime >> crvena >> zelena >> plava;
						s->obojiSelekciju(ime, crvena, zelena, plava); fleg = true;
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					}
					break;
				case 13:
					if (ucitaniPodaci) {
						std::cout << "Unesite ime selekcije\n";
						std::cin >> ime;
						s->obrisiSelekciju(ime); fleg = true;
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					}
					break;
				case 14:
					if (ucitaniPodaci) {
						dodavanjeSelekcije(s); fleg = true;
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					}
					break;
				case 15:
					if (!ucitaniPodaci) {
						s = pravljenjeSloja(); fleg = true;
						ucitaniPodaci = true;
					}
					else {
						std::cout << "\nVec je ucitana slika\n";
					} break;
				case 16:
					if (ucitaniPodaci) {
						dodajOperaciju(s); fleg = true;
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					}
					break;
				case 17:
					if (ucitaniPodaci) {
						std::cout << s->brojOperacija();
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					} break;
				case 18:
					if (ucitaniPodaci) {
						cuvanjeKompozitneUFajl(s);
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					}
					break;
				case 19:
					if (ucitaniPodaci) {
						citajKompozitnu(s); fleg = true;
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					}
					break;
				case 20:
					if (ucitaniPodaci) {
						izvrsiOperaciju(s); fleg = true;
					}
					else {
						std::cout << "\nNije ucitana slika\n";
					}
					break;
				default:
					break;
				}
			}
			catch (std::exception& e) {
				std::cout << e.what();
			}
		}
	}
	else {*/
		try
		{
			if (strcmp(argv[2] ,"1")==0) {
				std::string izvor = argv[1];
				std::string drufi = "kopija.xml";
				s = otvaranjeMetode(izvor);
				proveraAktivnosti(s);
				cuvanjeSlike(s, drufi);
				cuvanjeSlike(s, "kopija.bmp");
				sacuvajSveSelekcijeFajl(s);
				sacuvajSveAktivneSelekcije(s);
				std::ofstream fajl("brojOperacija.txt", std::ios::out);
				if (fajl.fail()) {
					fajl.close();
					throw GreskeMojCuvanje();
				}
				else {
					fajl << s->brojOperacija();
				}
				exit(s->brojSlojeva());
			}
			
			if (strcmp(argv[2], "2") == 0) {
				s = otvaranjeMetode("kopija.xml");
				cuvanjeSlike(s,argv[1]);


			}
			if (strcmp(argv[2], "3") == 0) {
				s = otvaranjeMetode("kopija.xml");
				int pom = s->brojSlojeva();
				dodajSloj(s,  argv[1], argv[3], argv[4], argv[5]);
				//cuvanjeSlike(s, "C:\\Users\\Nikola\\Desktop\\kopija33.bmp");
				cuvanjeSlike(s, "kopija.xml");
				cuvanjeSlike(s, "kopija.bmp");
				proveraAktivnosti(s);
				sacuvajSveSelekcijeFajl(s);
				sacuvajSveAktivneSelekcije(s);
				exit(s->brojSlojeva() - pom);

			}
			if (strcmp(argv[2], "6") == 0) {
				s = otvaranjeMetode("kopija.xml");
				
				s->obrisiSloj(atoi(argv[3]));
				
				cuvanjeSlike(s, "kopija.xml");
				cuvanjeSlike(s, "kopija.bmp");
				proveraAktivnosti(s);
				exit(1);
			}
			if (strcmp(argv[2], "7") == 0) {
				s = otvaranjeMetode("kopija.xml");
				
				if (strcmp(argv[3], "0") == 0) {
					std::shared_ptr<Sloj> sloj = s->dohvatiSloj(atoi(argv[4]));
					sloj->postaviProzirnost(atoi(argv[5]));
				}
				if (strcmp(argv[3], "1") == 0) {
					std::shared_ptr<Sloj> sloj = s->dohvatiSloj(atoi(argv[4]));
					sloj->postaviAktivnost((bool)(atoi(argv[5])));
					proveraAktivnosti(s);

				}
				if (strcmp(argv[3], "2") == 0) {
					std::shared_ptr<Sloj> sloj = s->dohvatiSloj(atoi(argv[4]));
					sloj->postaviVidljivost((bool)(atoi(argv[5])));
				}
				cuvanjeSlike(s, "kopija.xml");
				cuvanjeSlike(s, "kopija.bmp");
				

			}
			if (strcmp(argv[2], "9") == 0) {
				s = otvaranjeMetode("kopija.xml");
				selekcija = s->dohvatiAktivnuSelekciju();
				selekcija->postaviAktivnost((bool)atoi(argv[4]));

				cuvanjeSlike(s, "kopija.xml");
				cuvanjeSlike(s, "kopija.bmp");

			}
			if (strcmp(argv[2], "10") == 0) {
				s = otvaranjeMetode("kopija.xml");
				selekcija = s->dohvatiSelekcijuPoImenu(argv[3]);
				selekcija->postaviAktivnost((bool)atoi(argv[4]));
				sacuvajSveSelekcijeFajl(s);
				sacuvajSveAktivneSelekcije(s);
				cuvanjeSlike(s, "kopija.xml");
				cuvanjeSlike(s, "kopija.bmp");

			}
			if (strcmp(argv[2], "11") == 0) {
				s = otvaranjeMetode("kopija.xml");
				selekcija = s->dohvatiSelekciju(atoi(argv[3]));
				selekcija->postaviAktivnost((bool)atoi(argv[4]));

				cuvanjeSlike(s, "kopija.xml");
				cuvanjeSlike(s, "kopija.bmp");

			}
			if (strcmp(argv[2], "12") == 0) {
				s = otvaranjeMetode("kopija.xml");
				s->obojiSelekciju(argv[3], atoi(argv[4]), atoi(argv[5]), atoi(argv[6]));
				cuvanjeSlike(s, "kopija.xml");
				cuvanjeSlike(s, "kopija.bmp");

			}
			if (strcmp(argv[2], "13") == 0) {
				s = otvaranjeMetode("kopija.xml");
				s->obrisiSelekciju(argv[3]);
				sacuvajSveSelekcijeFajl(s);
				sacuvajSveAktivneSelekcije(s);
				cuvanjeSlike(s, "kopija.xml");
				cuvanjeSlike(s, "kopija.bmp");

			}
			if (strcmp(argv[2], "14") == 0) {
				s = otvaranjeMetode("kopija.xml");
				
				dodavanjeSelekcije(s, true);
				sacuvajSveSelekcijeFajl(s);
				sacuvajSveAktivneSelekcije(s);
				cuvanjeSlike(s, "kopija.xml");
			}
			if (strcmp(argv[2], "15") == 0) {
				s = otvaranjeMetode("kopija.xml");
				s = pravljenjeSloja(atoi(argv[3]) , atoi(argv[4]));

				cuvanjeSlike(s, "kopija.xml");
				cuvanjeSlike(s, "kopija.bmp");

			}
			if (strcmp(argv[2], "16") == 0) {
				s = otvaranjeMetode("kopija.xml");
				dodajOperaciju(s);
				int i = atoi(argv[3]);
				if (i == -1) {
					//dodavanje osnovne
					i = atoi(argv[4]);
					
					if (i > 11) {
						int redniBrojOperacije = atoi(argv[5]);
						std::string boja = argv[6];
						int konstanta = atoi(argv[7]);
						s->dodajOperaciju(std::make_shared<OsnovneOperacije>((OsnovneOperacije::OPERACIJE)
							redniBrojOperacije, boja, konstanta));

					}
					else {
						int redniBrojOperacije = atoi(argv[5]);
						std::string boja = argv[6];

						s->dodajOperaciju(std::make_shared<OsnovneOperacije>((OsnovneOperacije::OPERACIJE)
							redniBrojOperacije, boja));

					}
				}
				if (i == -2) {
					//dodavanje izvedene operacije
					i = atoi(argv[4]);
					int j  = atoi(argv[5]);
					if (j == -1) {
						if (i > 11) {
							int redniBrojOperacije = atoi(argv[5]);
							std::string boja = argv[6];
							int konstanta = atoi(argv[7]);
							s->dodajOperaciju(std::make_shared<OsnovneOperacije>((OsnovneOperacije::OPERACIJE)
								redniBrojOperacije, boja, konstanta));
						}
						else {
							int redniBrojOperacije = atoi(argv[5]);
							std::string boja = argv[6];
							s->dodajOperaciju(std::make_shared<OsnovneOperacije>((OsnovneOperacije::OPERACIJE)
								redniBrojOperacije, boja));
						}
					}
				}
				cuvanjeSlike(s, "kopija.xml");
				cuvanjeSlike(s, "kopija.bmp");

			}
		
			if (strcmp(argv[2], "18") == 0) {
				s = otvaranjeMetode("kopija.xml");
				cuvanjeKompozitneUFajl(s , argv[3]);
				cuvanjeSlike(s, "kopija.xml");
			}
			if (strcmp(argv[2], "19") == 0) {
				s = otvaranjeMetode("kopija.xml");
				citajKompozitnu(s , argv[3] , true);
				std::ofstream fajl("brojOperacija.txt", std::ios::out);
				if (fajl.fail()) {
					fajl.close();
					throw GreskeMojCuvanje();
				}
				else {
					fajl << s->brojOperacija();
				}
				cuvanjeSlike(s, "kopija.xml");
			}
			if (strcmp(argv[2], "20") == 0) {
				s = otvaranjeMetode("kopija.xml");
				izvrsiOperaciju(s, atoi(argv[3]));
				cuvanjeSlike(s, "kopija.xml");
				cuvanjeSlike(s, "kopija.bmp");

			}
	

		}
		catch (const std::exception& e)
		{
			std::cout << e.what();
		}

	//}
	return 0;
}













