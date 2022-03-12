#pragma once

#include"Selekcija.h"
#include"Sloj.h"
#include"NemaSelekcija.h"
#include"Operacija.h"
#include"SlozenaOperacija.h"


class Slika
{
	std::vector< std::shared_ptr<Operacija> > operacije;
	std::vector<std::shared_ptr<Sloj>> slojevi;
	std::vector<std::shared_ptr<Selekcija>> selekcije;
	int sirina, visina,brojKompozitnih;
	bool ucitaniPodaci;
public:

	Slika(std::string fajl,std::vector<std::vector<std::shared_ptr<Piksel>>> piks,int vis, int sir);
	Slika(std::string fajl,std::vector<std::vector<std::shared_ptr<Piksel>>> piks, int vis, int sir, int levo, int gore ,int prozir = 100, bool akt = true, bool vid = true);
	//pravljanje sloja
	Slika& napraviSloj(std::string fajl, std::vector<std::vector<std::shared_ptr<Piksel>>> piks,int visina, int sirina, int levo, int gore, int prozir =100, bool akt = true, bool vid = true);
	Slika& napraviSloj(std::string fajl, std::vector<std::vector<std::shared_ptr<Piksel>>> piks);
	Slika(std::shared_ptr<Sloj> sloj);
	int brojSelekcija()const;
	std::shared_ptr<Sloj> racunajSliku()const;
	
	Slika& dodajSloj(std::shared_ptr<Sloj> sloj);

	int brojSlojeva()const;
	std::shared_ptr<Sloj> dohvatiSloj(int i);
	Slika& obrisiSloj(int i);
	
	//rad sa selekcijom 
	bool imaAktivnaSelekcija()const;
	std::shared_ptr<Selekcija> dohvatiAktivnuSelekciju();
	std::shared_ptr<Selekcija> dohvatiSelekcijuPoImenu(std::string ime); 
	std::shared_ptr<Selekcija> dohvatiSelekciju(int i);
	Slika& obojiSelekciju(std::string ime, int crvena, int zelena, int plava);
	Slika& obrisiSelekciju(std::string ime);
	Slika& dodajSelekciju(std::shared_ptr<Selekcija> s);

	int dohvatiSirinu()const;
	int dohvatiVisinu()const;

	std::shared_ptr<Operacija> dohvatiOperaciju(int i);
	Slika& dodajOperaciju(std::shared_ptr<Operacija> oper);
	int brojOperacija()const;
	int dohvatiBrojKompozitnih()const;
	int brojSelekcija() {
		return selekcije.size();
	}
	friend std::ostream& operator << (std::ostream& out, const Slika& slika);
	bool ucitaniPodaciDohvati()const;
	int dohvatiBrojOperacija()const;

};

