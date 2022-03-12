#include "MojFormat.h"
#include"BMP.h"
std::shared_ptr<OsnovneOperacije> MojFormat::citajOsnovnuOperaciju(std::ifstream& fajl)
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

std::shared_ptr<SlozenaOperacija> MojFormat::citajSlozenuOperaciju(std::ifstream& fajl)
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

std::shared_ptr<Pravougaonik> MojFormat::citajPravougaonik(std::ifstream& fajl)
{
	std::string  linija;
	int visina, sirina, gore, levo;
	std::getline(fajl, linija);
	std::getline(fajl, linija);
	linija.erase(linija.begin(), linija.begin() + 10);
	linija.erase(linija.end() - 10, linija.end());
	visina = std::stoi(linija);
	std::getline(fajl, linija);
	linija.erase(linija.begin(), linija.begin() + 10);
	linija.erase(linija.end() - 10, linija.end());
	sirina = std::stoi(linija);
	std::getline(fajl, linija);
	linija.erase(linija.begin(), linija.begin() + 8);
	linija.erase(linija.end() - 8, linija.end());
	gore = std::stoi(linija);
	std::getline(fajl, linija);
	linija.erase(linija.begin(), linija.begin() + 8);
	linija.erase(linija.end() - 8, linija.end());
	levo = std::stoi(linija);
	std::getline(fajl, linija);
	return std::make_shared<Pravougaonik>(gore, levo, visina, sirina);
}

std::shared_ptr<Slika> MojFormat::citajSloj(std::ifstream& fajl)
{
	int visina, sirina, gore, levo, prozirnost;
	bool vidljivost, aktivnost;
	std::string putanja, linija;
	char pom8[8], pom9[9], pom6[6], pom7[7], pom10[10], pom12[12];
	fajl.read((char*)(&pom8), 8 * sizeof(char));
	fajl >> visina;
	fajl.read((char*)(&pom9), 9 * sizeof(char));
	fajl.get();
	fajl.read((char*)(&pom9), 9 * sizeof(char));
	fajl >> sirina;
	fajl.read((char*)(&pom9), 9 * sizeof(char));
	fajl.get();
	fajl.read((char*)(&pom7), 7 * sizeof(char));
	fajl >> gore;
	fajl.read((char*)(&pom7), 7 * sizeof(char));
	fajl.get();
	fajl.read((char*)(&pom7), 7 * sizeof(char));
	fajl >> levo;
	fajl.read((char*)(&pom7), 7 * sizeof(char));
	fajl.get();
	fajl.read((char*)(&pom9), 9 * sizeof(char));
	fajl.get();
	std::getline(fajl, putanja);
	putanja.erase(putanja.begin() + (putanja.size() - 11), putanja.end());
	std::getline(fajl, linija);
	aktivnost = (int)(linija[11]) - 48;
	std::getline(fajl, linija);
	vidljivost = (int)(linija[12]) - 48;
	fajl.read((char*)(&pom12), 12 * sizeof(char));
	fajl >> prozirnost;
	fajl.read((char*)(&pom12), 12 * sizeof(char));
	fajl.get();
	std::getline(fajl, linija);
	for (int i = 0; i < (int)pikseli.size(); i++) {
		pikseli[i].clear();
	}
	pikseli.clear();
	pikseli.resize(visina);
	for (int i = 0; i < visina; i++)
		pikseli[i].resize(sirina);
	for (int i = 0; i < visina; i++) {
		for (int j = 0; j < sirina; j++) {
			pikseli[i][j] = citajPiksel(fajl);
		}
	}
	return  std::make_shared<Slika>(putanja, std::move(pikseli), visina, sirina, levo, gore, prozirnost , aktivnost , vidljivost);
}

std::shared_ptr<Piksel> MojFormat::citajPiksel(std::ifstream& fajl)
{
	std::string linija;
	int crvena, plava, zelena, prozirnost;
	std::getline(fajl, linija);
	char pom8[8], pom9[9], pom6[6], pom7[7], pom12[12];
	fajl.read((char*)(&pom9), 9 * sizeof(char));
	fajl >> crvena;
	fajl.read((char*)(&pom9), 9 * sizeof(char));
	fajl.get();
	fajl.read((char*)(&pom9), 9 * sizeof(char));
	fajl >> plava;
	fajl.read((char*)(&pom9), 9 * sizeof(char));
	fajl.get();
	fajl.read((char*)(&pom12), 9 * sizeof(char));
	fajl >> zelena;
	fajl.read((char*)(&pom12), 10 * sizeof(char));
	fajl.get();
	fajl.read((char*)(&pom12), 12 * sizeof(char));
	fajl >> prozirnost;
	fajl.read((char*)(&pom12), 12 * sizeof(char));
	fajl.get(); fajl.get();
	fajl.get();
	std::getline(fajl, linija);
	return std::make_shared<Piksel>(crvena, zelena, plava, prozirnost);
}

std::shared_ptr<Selekcija> MojFormat::citajSelukciju(std::ifstream& fajl)
{
	std::string ime, linija;
	std::getline(fajl, ime);
	ime.erase(ime.begin(), ime.begin() + 6);
	ime.erase(ime.end() - 7, ime.end());
	std::getline(fajl, linija);
	linija.erase(linija.begin(), linija.begin() + 12);
	linija.erase(linija.end() - 13, linija.end());
	bool aktivnost = (bool)std::stoi(linija);
	std::vector<std::shared_ptr<Pravougaonik>> niz;
	std::getline(fajl, linija);
	linija.erase(linija.begin(), linija.begin() + 20);
	linija.erase(linija.end() - 20, linija.end());
	int brojPravouganika = std::stoi(linija);
	for (int i = 0; i < brojPravouganika; i++) {
		niz.push_back(citajPravougaonik(fajl));
	}
	return std::make_shared<Selekcija>(niz, ime, aktivnost);
}

std::shared_ptr<Slika> MojFormat::otvori(std::string ime, std::string nesto1, std::string nesto2, std::string nesto3)
{
	std::shared_ptr<Slika> slika;
	std::ifstream fajl(ime.c_str(), std::ios::in | std::ios::binary);
	for (int i = 0; i < (int)pikseli.size(); i++) {
		pikseli[i].clear();
	}
	pikseli.clear();
	if (fajl.fail()) {
		fajl.close();
		throw GreskaMojOtvaranje();
	}
	else {
		BMP bmp;
		//slika = bmp.otvori("C:\\Users\\Nikola\\Desktop\\slika.bmp");
		bool prviSloj = true;
		std::string linija;
		while (std::getline(fajl, linija))
		{
			if (linija.find("<sloj>") != std::string::npos) {
				if (!prviSloj) {
					std::shared_ptr<Slika> s = citajSloj(fajl);
					slika->dodajSloj(s->dohvatiSloj(0));
				}
				else {
					slika = citajSloj(fajl);
					prviSloj = false;
				}
			}
			if (linija.find("<selekcija>") != std::string::npos) {
				slika->dodajSelekciju(citajSelukciju(fajl));
			}
			if (linija.find("<osnovnaOperacija>") != std::string::npos) {
				slika->dodajOperaciju(citajOsnovnuOperaciju(fajl));
			}
			if (linija.find("<slozenaOperacija>") != std::string::npos) {
				slika->dodajOperaciju(citajSlozenuOperaciju(fajl));
			}
		}
	}

	return slika;
}

void MojFormat::sacuvaj(std::string ime, std::shared_ptr<Slika> slika)
{
	std::ofstream fajl(ime.c_str(), std::ios::out);
	if (fajl.fail()) {
		fajl.close();
		throw GreskeMojCuvanje();
	}
	else
	{
		for (int i = 0; i < slika->brojSlojeva(); i++) {
			fajl << "<sloj>\n";

			fajl << "<visina>" << slika->dohvatiSloj(i)->dohvatiVisinu() << "</visina>\n"
				<< "<sirina>" << slika->dohvatiSloj(i)->dohvatiSirinu() << "</sirina>\n"
				<< "<gore>" << slika->dohvatiSloj(i)->dohvatiGore() << "</gore>\n"
				<< "<levo>" << slika->dohvatiSloj(i)->dohvatiLevo() << "</levo>\n"
				<< "<putanja>" << slika->dohvatiSloj(i)->dohvatiPutanju() << "</putanja>\n"
				<< "<aktivnost>" << slika->dohvatiSloj(i)->dohvatiAktivna() << "</aktivnost>\n"
				<< "<vidljivost>" << slika->dohvatiSloj(i)->dohvatiVidljivost() << "</vidljivost>\n"
				<< "<prozirnost>" << slika->dohvatiSloj(i)->dohvatiProzirnost() << "</prozirnost>\n";

			std::shared_ptr<Sloj> s = slika->dohvatiSloj(i);
			for (int j = 0; j < s->dohvatiDodataVisina(); j++) {
				for (int k = 0; k < s->dohvatiDodataSirina(); k++) {
					if (s->daLiJePikselUTomSloju(j, k)) {
						std::shared_ptr<Piksel> p = s->dohvatiPiskel(j, k);
						fajl << "<piksel>\n"
							<< "\t<crvena>" << p->dohvatiCrvena() << "</crvena>\n"
							<< "\t<plava>" << p->dohvatiPlava() << "</plava>\n"
							<< "\t<zelena>" << p->dohvatiZelena() << "</zelena>\n"
							<< "\t<prozrnost>" << p->dohvatiProzirnost() << "</prozirnost>\n"
							<< "</piksel>\n";
					}
				}
			}
			fajl << "</sloj>\n";
		}

		for (int i = 0; i < slika->brojSelekcija(); i++) {

			fajl << "<selekcija>\n\t<ime>" << slika->dohvatiSelekciju(i)->dohvatiIme() << "</ime>\n"
				<< "\t" << "<aktivnost>" << slika->dohvatiSelekciju(i)->dohvatiAktivna() << "</aktivnost>\n"
				<< "\t<brojPravougaonika>" << slika->dohvatiSelekciju(i)->dohvatiBrojPravougaonika() << "</brojPravougaonik>\n";
			std::shared_ptr<Selekcija> s = slika->dohvatiSelekciju(i);
			for (int j = 0; j < s->dohvatiBrojPravougaonika(); j++) {
				fajl << "\t<pravougaonik>\n"
					<< "\t\t<visina>" << s->dohvatiPravougaonik(j)->dohvatiVisinu() << "</visina>\n"
					<< "\t\t<sirina>" << s->dohvatiPravougaonik(j)->dohvatiSirinu() << "</sirina>\n"
					<< "\t\t<gore>" << s->dohvatiPravougaonik(j)->dohvatiGore() << "</gore>\n"
					<< "\t\t<levo>" << s->dohvatiPravougaonik(j)->dohvatiLevo() << "</levo>\n"
					<< "\t</pravougaonik>\n";
			}
			fajl << "</selekcija>\n";
		}
		for (int i = 0; i < slika->dohvatiBrojOperacija(); i++) {
			slika->dohvatiOperaciju(i)->ispisiUFormat(fajl);
		}
		fajl.close();
	}
}


