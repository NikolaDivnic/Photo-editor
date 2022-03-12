#pragma once
#include "Operacija.h"
#include"NepravilnaBoja.h"
#include"LosaOperacija.h"
class Slika;
class OsnovneOperacije : public Operacija
{
	//osnovne aritmeticke operacije
	void sabiranje(std::shared_ptr<Piksel> p);//da 
	void oduzimanje(std::shared_ptr<Piksel> p);
	void inverznoOduzimanje(std::shared_ptr<Piksel> p);
	void mnozenje(std::shared_ptr<Piksel> p);
	void deljenje(std::shared_ptr<Piksel> p);
	void inverznoDeljenje(std::shared_ptr<Piksel> p);
	
	//funkcije
	void power(std::shared_ptr<Piksel> p);//stepenovanje
	void log(std::shared_ptr<Piksel> p);//logaritam
	void abs(std::shared_ptr<Piksel> p);//apsolutna vrednost
	void min(std::shared_ptr<Piksel> p);//sve komponente se postavljaju na min vrednost
	void max(std::shared_ptr<Piksel> p);//sve komponente se postavljaju na max vrednost

	//predefinisane funkcije
	void negacijaBoje(std::shared_ptr<Piksel> p);//inverzija
	void pretvaranjeUSivu(std::shared_ptr<Piksel> p);
	void pretvaranjeUCrnoBelu(std::shared_ptr<Piksel> p);
	
public:
	enum OPERACIJE { PLUS, MINUS ,INVERZNOODUZIMANJE,MNOZENJE,DELJENJE,
		INVERZNODELJENJE,POWER,LOG,ABS,MIN,MAX,NEGACIJABOJE, PRETVARANJEUSIVU,PRETVARANJEUCRNOBELU , MEDIJANA};
private:
	OPERACIJE operacija;
	std::string boja;
	int con;
public:
	OsnovneOperacije(OPERACIJE o , std::string boja);
	OsnovneOperacije(OPERACIJE o, std::string boja , int c);
	void izvrsi(Slika& slika) override;
	char vrsta()const override;
	int dohvatiOperaciju()const;
	std::string dohvatiBoju()const;
	int dohvatiKonstantu()const;
	std::ostream& ispisiUFormat(std::ostream& fajl)override;
};

