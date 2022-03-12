#include "Sloj.h"
#include"Slika.h"


Sloj::Sloj(std::string ime, Slika* s, std::vector<std::vector<std::shared_ptr<Piksel>>> piks, int vis, int sir, int lev, int gor, int proz,  bool akt , bool vid ):pikseli(std::move(piks))
{
	if (proz < 0) proz = 0;
	if (proz > 100)proz = 100;
	prozirnost = proz;
	aktivan = akt;
	vidljivost = vid;
	if (sir < 0) sir = 0;
	if (vis < 0) vis = 0;
	if (lev < 0)lev = 0;
	if (gor < 0)gor = 0;
	levo = lev;
	gore = gor;
	dodataSirina = sir + levo;
	sirina = sir;
	dodataVisina = vis + gore;
	visina = vis;
	if (s->brojSlojeva() && (dodataSirina < s->dohvatiSloj(0)->dohvatiDodataSirina())) {
		dodataSirina = s->dohvatiSloj(0)->dohvatiDodataSirina();
	}

	if (s->brojSlojeva() && (dodataSirina > s->dohvatiSloj(0)->dohvatiDodataSirina())) {
		for (int i = 0; i < s->brojSlojeva(); i++) {
			s->dohvatiSloj(i)->dopuniDesno(levo + sirina);
		}
	}

	if (s->brojSlojeva() && (dodataVisina < s->dohvatiSloj(0)->dohvatiDodataVisina()))
		dodataVisina = s->dohvatiSloj(0)->dohvatiDodataSirina();

	if (s->brojSlojeva() && (dodataVisina > s->dohvatiSloj(0)->dohvatiDodataVisina()))
	{
		for (int i = 0; i < s->brojSlojeva(); i++) {
			s->dohvatiSloj(i)->dopuniDole(gore + visina);
		}
	}
	putanja = ime;

}

Sloj::Sloj(std::string ime, Slika* slika, std::vector<std::vector<std::shared_ptr<Piksel>>> piks):pikseli(std::move(piks))
{
	if (slika->brojSlojeva()) {
		dodataSirina = sirina = slika->dohvatiSloj(0)->dohvatiSirinu();
		dodataVisina = visina = slika->dohvatiSloj(0)->dohvatiVisinu();
	}
	else {
		dodataSirina = sirina = slika->dohvatiSirinu();
		dodataVisina = visina = slika->dohvatiVisinu();
	}
	pikseli.resize(visina);
	for (int i = 0; i < visina; i++)
		pikseli[i].resize(sirina);
	prozirnost = 100;
	levo = gore = 0;
	aktivan = true;
	vidljivost = true;
	putanja = ime;
}

Sloj& Sloj::napraviPiksel(int crvena, int zelena, int plava, int gore, int levo, int proz)
{
	if (gore < 0 || levo < 0 || gore >=(int) pikseli.size() || levo >= (int)pikseli[0].size()) throw Granice();
	pikseli[gore][levo] = std::make_shared<Piksel>(std::move(Piksel(crvena, zelena, plava, gore + this->gore, levo + this->levo, proz)));
	return *this;
}

std::string Sloj::dohvatiPutanju() const {
	return putanja;
}

bool Sloj::daLiJePikselUTomSloju(int i, int j) const
{
	return (gore <= i) && (i < gore + visina) && (j >= levo) && (j < levo + sirina);
}

Sloj::Sloj(int vis, int sir, int proz)
{
	if (proz < 0) proz = 0;
	if (proz > 100)proz = 100;
	prozirnost = proz;
	aktivan = true;
	vidljivost = true;
	if (sir < 0) sir = 0;
	if (vis < 0) vis = 0;
	dodataSirina = sirina = sir;
	dodataVisina = visina = vis;
	levo = gore = 0;
	pikseli.resize(visina);
	for (int i = 0; i < visina; i++)
		pikseli[i].resize(sirina);
	for (int i = 0; i < vis; i++) {
		for (int j = 0; j < sir; j++) {
			napraviPiksel(0, 0, 0, i, j);
		}
	}
}

std::shared_ptr<Piksel> Sloj::dohvatiPiskel(int i, int j)
{
	if ((i - gore) >= visina || (j - levo) >= (sirina) || i < 0 || j < 0)
		throw Granice();
	return pikseli[i - gore][j - levo];
}

bool Sloj::dohvatiAktivna() const
{
	return aktivan;
}

int Sloj::dohvatiProzirnost() const
{
	return prozirnost;
}

bool Sloj::dohvatiVidljivost() const
{
	return vidljivost;
}

void Sloj::postaviProzirnost(int prozor)
{
	if (prozor < 0)prozor = 0;
	if (prozor > 100) prozor = 100;
	prozirnost = prozor;
	for (int i = 0; i < visina; i++)
	{
		for (int j = 0; j < sirina; j++) {
			if (daLiJePikselUTomSloju(i,j))
			dohvatiPiskel(i, j)->postaviProzirnost(prozor);
		}
	}
}

void Sloj::postaviAktivnost(bool akt)
{
	aktivan = akt;
}

void Sloj::postaviVidljivost(bool vidljivo)
{
	vidljivost = vidljivo;
}

int Sloj::dohvatiSirinu() const
{
	return sirina;
}

int Sloj::dohvatiVisinu() const
{
	return visina;
}

int Sloj::dohvatiLevo() const
{
	return levo;
}

int Sloj::dohvatiGore() const
{
	return gore;
}

void Sloj::dopuniLevo(int lev)
{
	dodataSirina += levo;

}

void Sloj::dopuniDesno(int des)
{
	dodataSirina = des;
}

void Sloj::dopuniGore(int gor)
{

	dodataVisina += gore;
}

void Sloj::dopuniDole(int dol)
{
	dodataVisina = dol;
}

void Sloj::brisi()
{
	for (int i = 0; i < visina; i++) {
		pikseli[i].clear();
	}
	pikseli.clear();
}

int Sloj::dohvatiDodataSirina() const
{
	return dodataSirina;
}

int Sloj::dohvatiDodataVisina() const
{
	return dodataVisina;
}

std::ostream& operator<<(std::ostream& out, const Sloj& sloj)
{
	for (int i = 0; i < sloj.dohvatiVisinu(); i++) {
		for (int j = 0; j < sloj.dohvatiSirinu(); j++) {
			out << *sloj.pikseli[i][j];
		}
		out << "\n";
	}
	return out;
}
