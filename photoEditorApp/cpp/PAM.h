#pragma once
#include "Formater.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include"GreskePAM.h"
#include<vector>
class PAM :
	public Formater
{
	struct Heder {

		unsigned char sirinaOznaka[5];
		unsigned int sirina;
		unsigned char visinaOznaka[6];
		int visina;
		unsigned char dubinaOznaka[5];
		int dubina;
		unsigned char maxOznaka[6];
		unsigned int max;
		char tipOznaka[8] , tip[10];
		char kraj[6];
	
	};
	void ucitavanjeHedera(std::ifstream& fajl, Heder*heder);
	void citanjeRGB(std::ifstream& fajl, int visina, int sirina);
	void citanjeRGB_ALPHA(std::ifstream& fajl, int visina, int sirina);
public:
	std::shared_ptr<Slika> otvori(std::string fajl, std::string nesto1, std::string nesto2, std::string nesto3)override;
	void  sacuvaj(std::string fajl, std::shared_ptr<Sloj> s)override;

};

