#include "Slika.h"

Slika& Slika::dodajSelekciju(std::shared_ptr<Selekcija> s)
{
	for (int i = 0; i < s->dohvatiBrojPravougaonika(); i++) {
		if ((s->dohvatiPravougaonik(i)->dohvatiLevo() + s->dohvatiPravougaonik(i)->dohvatiSirinu()) > dohvatiSloj(0)->dohvatiDodataSirina()
			|| (s->dohvatiPravougaonik(i)->dohvatiGore() + s->dohvatiPravougaonik(i)->dohvatiVisinu()) >dohvatiSloj(0)->dohvatiDodataVisina())
			throw Granice();
	}
	selekcije.push_back(s);
	return *this;
}
int Slika::brojSelekcija() const {
	return selekcije.size();
}
std::shared_ptr<Sloj> Slika::racunajSliku()const
{
	if (slojevi.size() == 0)
		throw NemaSlojeva();
	std::shared_ptr<Sloj> sloj = std::make_shared<Sloj>(slojevi[0]->dohvatiDodataVisina(), slojevi[0]->dohvatiDodataSirina());
	for (int i = 0; i < brojSlojeva(); i++) {
		if (slojevi[i]->dohvatiVidljivost())
			for (int j = 0; j < slojevi[0]->dohvatiDodataVisina(); j++) {
				for (int k = 0; k < slojevi[0]->dohvatiDodataSirina(); k++) {
					if ((j < slojevi[i]->dohvatiGore() + slojevi[i]->dohvatiVisinu()) && j >= slojevi[i]->dohvatiGore()
						&& (k < slojevi[i]->dohvatiLevo() + slojevi[i]->dohvatiSirinu()) && k >= slojevi[i]->dohvatiLevo()) {
						std::shared_ptr<Piksel> p = sloj->dohvatiPiskel(j, k);
						std::shared_ptr<Piksel> p2 = slojevi[i]->dohvatiPiskel(j, k);
						int c = (int)((slojevi[i]->dohvatiProzirnost() * p2->dohvatiCrvena() + (100 - slojevi[i]->dohvatiProzirnost()) * p->dohvatiCrvena()) / 100);
						int z = (int)((slojevi[i]->dohvatiProzirnost() * p2->dohvatiZelena() + (100 - slojevi[i]->dohvatiProzirnost()) * p->dohvatiZelena()) / 100);
						int pp = (int)((slojevi[i]->dohvatiProzirnost() * p2->dohvatiPlava() + (100 - slojevi[i]->dohvatiProzirnost()) * p->dohvatiPlava()) / 100);
						sloj->dohvatiPiskel(j, k)->postaviBoju(c, z, pp);
					}

				}
			}
	}
	return sloj;
}
Slika& Slika::dodajSloj(std::shared_ptr<Sloj> sloj)
{

	if (brojSlojeva() && (sloj->dohvatiDodataSirina() > dohvatiSloj(0)->dohvatiDodataSirina())) {
		for (int i = 0; i < brojSlojeva(); i++) {
			dohvatiSloj(i)->dopuniDesno(sloj->dohvatiLevo() + sloj->dohvatiSirinu());
		}
	}
	if (brojSlojeva() && (sloj->dohvatiDodataSirina() < dohvatiSloj(0)->dohvatiDodataSirina())) {
		sloj->dopuniDesno(dohvatiSloj(0)->dohvatiSirinu());
	}

	if (brojSlojeva() && (sloj->dohvatiDodataVisina() < dohvatiSloj(0)->dohvatiDodataVisina()))
		sloj->dopuniDole(dohvatiSloj(0)->dohvatiVisinu());

	if (brojSlojeva() && (sloj->dohvatiDodataVisina() > dohvatiSloj(0)->dohvatiDodataVisina()))
	{
		for (int i = 0; i < brojSlojeva(); i++) {
			dohvatiSloj(i)->dopuniDole(sloj->dohvatiGore() + sloj->dohvatiVisinu());
		}
	}
	slojevi.push_back(sloj);
	visina = slojevi[0]->dohvatiDodataVisina();
	sirina = slojevi[0]->dohvatiDodataSirina();
	return *this;
}
int Slika::brojSlojeva() const
{
	return slojevi.size();
}
std::shared_ptr<Sloj> Slika::dohvatiSloj(int i)
{
	if (i < 0 || i >= (int)slojevi.size())
		throw Granice();
	return slojevi[i];
}

Slika& Slika::obrisiSloj(int i)
{
	if (i < 0 || i >= (int)slojevi.size())
		throw Granice();
	slojevi[i]->brisi();
	slojevi.erase(slojevi.begin() + i);
	return *this;
}

Slika& Slika::obrisiSelekciju(std::string ime)
{
	int i;
	for (i = 0; i < (int)selekcije.size(); i++) {
		if (selekcije[i]->dohvatiIme() == ime) {
			selekcije.erase(selekcije.begin() + i);
			break;
		}
	}
	return *this;
}

std::shared_ptr<Selekcija> Slika::dohvatiSelekcijuPoImenu(std::string ime)
{
	for (int i = 0; i < (int)selekcije.size(); i++)
		if (ime == selekcije[i]->dohvatiIme())return selekcije[i];
	throw NemaSelekcija();
	return selekcije[0];
}


std::shared_ptr<Selekcija> Slika::dohvatiSelekciju(int i) {
	if (i < 0 || i >= (int)selekcije.size()) {
		throw Granice();
	}
	return selekcije[i];
}

int Slika::dohvatiSirinu() const
{
	return sirina;
}

int Slika::dohvatiVisinu() const
{
	return visina;
}

Slika& Slika::obojiSelekciju(std::string ime, int crvena, int zelena, int plava)
{
	std::shared_ptr<Selekcija> s = dohvatiSelekcijuPoImenu(ime);
	if (s->dohvatiAktivna())
	for (int i = 0; i < s->dohvatiBrojPravougaonika(); i++) {
		for (int j = s->dohvatiPravougaonik(i)->dohvatiGore(); j < s->dohvatiPravougaonik(i)->dohvatiGore() +
			s->dohvatiPravougaonik(i)->dohvatiVisinu(); j++) {
			for (int k = s->dohvatiPravougaonik(i)->dohvatiLevo(); k < s->dohvatiPravougaonik(i)->dohvatiSirinu() +
				s->dohvatiPravougaonik(i)->dohvatiLevo(); k++) {
				for (int l = 0; l < (int)slojevi.size(); l++) {
					if (slojevi[l]->dohvatiAktivna() && slojevi[l]->daLiJePikselUTomSloju(j, k))
						slojevi[l]->dohvatiPiskel(j, k)->postaviBoju(crvena, zelena, plava);
				}
			}
		}
	}
	return *this;
}

std::shared_ptr<Operacija> Slika::dohvatiOperaciju(int i)
{
	if (i >= (int)operacije.size() || i < 0)
		throw NemaOperacije();
	return operacije[i];
}

Slika& Slika::dodajOperaciju(std::shared_ptr<Operacija> oper)
{
	operacije.push_back(oper);
	if (oper->vrsta() == 's')
		brojKompozitnih++;
	return *this;
}
int Slika::dohvatiBrojKompozitnih()const {
	return brojKompozitnih;
}
int Slika::brojOperacija() const
{
	return operacije.size();
}

bool Slika::ucitaniPodaciDohvati() const
{
	return ucitaniPodaci;
}

int Slika::dohvatiBrojOperacija() const
{
	return operacije.size();
}





bool Slika::imaAktivnaSelekcija() const
{
	for (int i = 0; i < (int)selekcije.size(); i++)
		if (selekcije[i]->dohvatiAktivna())return true;
	return false;
}

std::shared_ptr<Selekcija> Slika::dohvatiAktivnuSelekciju()
{

	for (int i = 0; i < (int)selekcije.size(); i++) {
		if (selekcije[i]->dohvatiAktivna()) return selekcije[i];
	}
	throw NemaSelekcija();
	return selekcije[0];
}



Slika::Slika(std::string ime, std::vector<std::vector<std::shared_ptr<Piksel>>> piks, int vis, int sir)
{
	brojKompozitnih = 0;
	if (sir < 0) sir = 0;
	if (vis < 0) vis = 0;
	sirina = sir;
	visina = vis;
	ucitaniPodaci = true;
	napraviSloj(ime, std::move(piks));

}

Slika::Slika(std::string ime, std::vector<std::vector<std::shared_ptr<Piksel>>> piks, int vis, int sir, int levo, int gore, int prozir,bool akt , bool vid )
{
	brojKompozitnih = 0;
	if (vis < 0)vis = 0;
	if (sir < 0) sir = 0;
	if (levo < 0) levo = 0;
	if (gore < 0)gore = 0;
	if (prozir < 0)prozir = 0;
	if (prozir > 100) prozir = 100;
	ucitaniPodaci = true;
	napraviSloj(ime, std::move(piks), vis, sir, levo, gore, prozir, akt, vid);

}



Slika& Slika::napraviSloj(std::string ime, std::vector<std::vector<std::shared_ptr<Piksel>>> piks, int visina, int sirina, int levo, int gore, int prozir, bool akt , bool vid )
{
	std::shared_ptr<Sloj>  s = std::make_shared<Sloj>(Sloj(ime, this, std::move(piks), visina, sirina, levo, gore, prozir , akt, vid));
	slojevi.push_back(s);
	visina = slojevi[0]->dohvatiDodataVisina();
	sirina = slojevi[0]->dohvatiDodataSirina();
	return *this;
}



Slika& Slika::napraviSloj(std::string ime, std::vector<std::vector<std::shared_ptr<Piksel>>> piks)
{
	std::shared_ptr<Sloj> s = std::make_shared<Sloj>(Sloj(ime, this, std::move(piks)));
	slojevi.push_back(s);
	visina = slojevi[0]->dohvatiDodataVisina();
	sirina = slojevi[0]->dohvatiDodataSirina();
	return *this;
}

Slika::Slika(std::shared_ptr<Sloj> sloj)
{
	dodajSloj(sloj);
	brojKompozitnih = 0;
}

std::ostream& operator<<(std::ostream& out, const Slika& slika)
{
	out << *slika.racunajSliku();
	return out;
}
