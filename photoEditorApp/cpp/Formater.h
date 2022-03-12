#pragma once
#include<iostream>
#include"Slika.h"
#include<vector>
#include"GreskeMojFormat.h"
class Formater
{
protected:
	std::vector<std::vector<std::shared_ptr<Piksel>>> pikseli;
public:
	virtual std::shared_ptr<Slika> otvori(std::string fajl, std::string nesto1, std::string nesto2, std::string nesto3) = 0;
	virtual void  sacuvaj(std::string fajl, std::shared_ptr<Sloj> s) = 0;
	
};



