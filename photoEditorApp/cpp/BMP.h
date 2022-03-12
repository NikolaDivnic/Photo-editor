#pragma once
#include "Formater.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include"GreskeBmp.h"
class BMP :
	public Formater
{
	struct Heder
	{
		unsigned int  velicinaFajla;
		unsigned short int rezerva1;
		unsigned short int rezerva2;
		unsigned int pomeraj;
	};

	struct Info24
	{
		unsigned int velicinaHedera;
		int sirina;
		int visina;
		unsigned short int brojAviona;//??Broj boja koje avioni koriste??
		unsigned short int bitoviPoPikselu;
		unsigned int kompresija;
		unsigned int velicinaPodatka;
		int pikseliHorizontalno;
		int pikseliVertikalno;
		unsigned int brojBoja;//uvek sve nule
		unsigned int brojVaznihBoja;//uvek sve nule
	};
	struct Info32
	{
	
		unsigned int pom1, pom2, pom3, pom4, pom5
			, pom6, pom7, pom8, pom9, pom10, pom11,
			pom12, pom13, pom14,pom15,pom16,pom17;
	};

	void ucitavanjeTridesetDva(int visina, int sirina, std::ifstream& ,bool okrenut);
	void ucitavanjeDvadesetCetiri(int visina, int sirina, std::ifstream&, bool okrenut);
	void cuvanjeHedera(std::ofstream&, std::shared_ptr<Sloj> s);
	void cuvanjePrviInfo(std::ofstream&, std::shared_ptr<Sloj> s);
	void cuvanjeDrogogDelaInfo(std::ofstream&, std::shared_ptr<Sloj> s);
	void cuvanjePiksela(std::ofstream&, std::shared_ptr<Sloj> s);

public :
	std::shared_ptr<Slika> otvori(std::string fajl ,std::string nesto1, std::string nesto2, std::string nesto3);
	void  sacuvaj(std::string fajl , std::shared_ptr<Sloj> s)override;
	
};

