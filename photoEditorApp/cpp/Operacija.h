#pragma once
#include"Selekcija.h"
#include"Sloj.h"
class Slika;
class Operacija
{
public :
	virtual void  izvrsi(Slika& slika) = 0;
	virtual char vrsta()const = 0;
	virtual std::ostream& ispisiUFormat(std::ostream&) = 0;
};


