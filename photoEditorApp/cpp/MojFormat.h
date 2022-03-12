#pragma once
#include "Formater.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include"GreskeMojFormat.h"

class MojFormat :
	public Formater
{
	std::shared_ptr<OsnovneOperacije> citajOsnovnuOperaciju(std::ifstream& fajl);
	std::shared_ptr<SlozenaOperacija> citajSlozenuOperaciju(std::ifstream& fajl);
	std::shared_ptr<Pravougaonik> citajPravougaonik(std::ifstream& fajl);
	std::shared_ptr<Slika> citajSloj(std::ifstream& fajl);
	std::shared_ptr<Piksel> citajPiksel(std::ifstream& fajl);
	
public:
	std::shared_ptr<Selekcija> citajSelukciju(std::ifstream& fajl);
	std::shared_ptr<Slika> otvori(std::string fajl, std::string nesto1, std::string nesto2, std::string nesto3) override;
	void  sacuvaj(std::string fajl, std::shared_ptr<Slika> slika);
	void sacuvaj(std::string fajl, std::shared_ptr<Sloj> sloj)override {}
	
};

