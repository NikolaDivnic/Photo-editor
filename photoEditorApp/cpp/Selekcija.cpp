#include "Selekcija.h"

Selekcija::Selekcija(std::vector<std::shared_ptr<Pravougaonik>> niz , std::string im ,bool akt)
{
	for (int i = 0; i<niz.size(); i++) {
		nizPravougaonika.push_back(niz[i]);
	}
	aktivna = akt;
	ime = im;
}



std::string Selekcija::dohvatiIme()const
{
	return ime;
}

std::vector<std::shared_ptr<Pravougaonik>> Selekcija::dohvatiPravougaonike() {
	return nizPravougaonika;
}

bool Selekcija::dohvatiAktivna()const
{
	return aktivna;
}

int Selekcija::dohvatiBrojPravougaonika() const
{
	return nizPravougaonika.size();
}

std::shared_ptr<Pravougaonik> Selekcija::dohvatiPravougaonik(int i)
{
	if (i >= nizPravougaonika.size() || i < 0)
		throw Granice();
	return nizPravougaonika[i];
}

void Selekcija::postaviAktivnost(bool akt)
{
	aktivna = akt;
}

void Selekcija::brisi() {
	nizPravougaonika.clear();
}
