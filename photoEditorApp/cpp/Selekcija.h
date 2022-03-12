#pragma once
#include<iostream>
#include<string.h>
#include"Granice.h"
#include<vector>
#include"Pravougaonik.h"

class Selekcija
{
	std::vector<std::shared_ptr<Pravougaonik>> nizPravougaonika;
	std::string ime;
	bool aktivna;

public :
	Selekcija(std::vector<std::shared_ptr<Pravougaonik>> niz , std::string im , bool akt = true);
	std::string dohvatiIme()const;
	std::vector<std::shared_ptr<Pravougaonik>> dohvatiPravougaonike();
	bool dohvatiAktivna()const;
	int dohvatiBrojPravougaonika()const;
	std::shared_ptr<Pravougaonik> dohvatiPravougaonik(int i);
	void postaviAktivnost(bool akt);
	void brisi();
	
};

