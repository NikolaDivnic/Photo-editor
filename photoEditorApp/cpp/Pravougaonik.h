#pragma once
#include<iostream>
class Pravougaonik
{
	int levo, gore, sirina, visina;
	
public :
	
	Pravougaonik(int gore, int lev, int vis, int sir);

	// dohvatanje pozicije pravougaonika
	int dohvatiSirinu() const;
	int dohvatiVisinu()const;
	int dohvatiLevo()const;
	int dohvatiGore()const;
};

