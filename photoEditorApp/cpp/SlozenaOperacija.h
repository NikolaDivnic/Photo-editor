#pragma once
#include "Operacija.h"
#include"OsnovneOperacije.h"
#include"Granice.h"
#include<vector>

class SlozenaOperacija :
	public Operacija
{
	std::vector<std::shared_ptr<Operacija>>operacije;
public :
	SlozenaOperacija& dodajOperaciju(std::shared_ptr<Operacija> o);
	int dohvatiBrojOperacija()const;
	SlozenaOperacija& skloniOperaciju(int i);
	void izvrsi(Slika& slika) override;
	char vrsta()const override;
	std::shared_ptr<Operacija> dohvatiOperaciju(int i);
	std::ostream& ispisiUFormat(std::ostream& fajl)override;
};

