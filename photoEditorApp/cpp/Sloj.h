#pragma once
#include"Piksel.h"
#include"Operacija.h"
#include"Granice.h"
#include<vector>
#include<string.h>

class Slika;
class Sloj
{
	friend class Slika;
	std::vector<std::vector<std::shared_ptr<Piksel>>> pikseli;
	int prozirnost;
	bool aktivan, vidljivost;
	std::string putanja;
	int sirina, visina, levo , gore;//osnovna slika
	int dodataSirina, dodataVisina;//prosirena slika dodatim pikselima
	Sloj(std::string fajl, Slika* slika, std::vector<std::vector<std::shared_ptr<Piksel>>> piks);
	Sloj(std::string fajl, Slika* slika, std::vector<std::vector<std::shared_ptr<Piksel>>> piks, int vis, int sir, int levo, int gore, int proz = 100, bool akt = true, bool vid = true);

	Sloj& napraviPiksel(int crvena, int zelena, int plava, int levo, int gore, int proz = 100);
	
public:

	std::string dohvatiPutanju()const;
	bool daLiJePikselUTomSloju(int i, int j)const;

	Sloj(int vis, int sir,int proz = 100 );
	
	//dohvatanje svega osim dimenzija
	std::shared_ptr<Piksel> dohvatiPiskel(int i, int j);
	bool dohvatiAktivna()const;
	int dohvatiProzirnost()const;
	bool dohvatiVidljivost()const;
	
	// osnovni seteri
	void postaviProzirnost(int prozor);
	void postaviAktivnost(bool akt);
	void postaviVidljivost(bool vidljivo);

	//geteri prave slike bez dodatih piksela
	int dohvatiSirinu() const;
	int dohvatiVisinu()const;
	int dohvatiLevo()const;
	int dohvatiGore()const;

	//geteri slike sa dodatim pikselima
	int dohvatiDodataSirina()const;
	int dohvatiDodataVisina()const;


	//dopunjavanje providnim pikselima
	void dopuniLevo(int lev);
	void dopuniDesno(int des);
	void dopuniGore(int gor);
	void dopuniDole(int dol);
	
	void brisi();
	friend std::ostream& operator << (std::ostream& out, const Sloj& c);
};

