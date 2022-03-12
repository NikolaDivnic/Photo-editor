#pragma once
#include<iostream>
#include<math.h>
class Sloj;
class Piksel
{
	friend class Sloj;
	int prozirnost;
	int crvena, zelena, plava;
	int y, x;
	Piksel(int cr, int ze, int pl, int le, int go,int prozir  =100);
	
public:
	Piksel(int cr, int ze, int pla, int prozir = 100);
	void postaviBoju(int c, int z, int p);
	int dohvatiCrvena()const;
	int dohvatiZelena()const;
	int dohvatiPlava()const;
	int dohvatiY()const;
	int dohvatiX()const;
	int dohvatiProzirnost()const;

	void postaviProzirnost(int proz);
	void postaviCrvenu(int crv);
	void postaviZelenu(int zel);
	void postaviPlavu(int pla);

	friend std::ostream& operator << (std::ostream& out, const Piksel& piksel);
};

