#include "Piksel.h"
#include"Sloj.h"

Piksel::Piksel(int cr, int ze, int pl, int go,int le, int prozir)
{
	if (prozir < 0) prozir = 0;
	if (prozir > 100) prozir = 100;
	prozirnost = prozir;
	postaviBoju(cr, ze, pl);
	if (go < 0)go = 0;
	if (le < 0)le = 0;
	y = go;
	x = le;
}


Piksel::Piksel(int cr, int ze, int pla , int prozir)
{
	postaviBoju(cr, ze, pla);
	x = y = prozirnost = prozir;

}

void Piksel::postaviBoju(int c, int z, int p)
{
	if (c > 255)c = 255;
	if (c< 0) c = 0;
	if (z > 255)z = 255;
	if (z < 0) z = 0;
	if (p > 255)p = 255;
	if (p < 0) p = 0;
	crvena = c;
	zelena = z;
	plava = p;
}



int Piksel::dohvatiCrvena() const
{
	return crvena;
}

int Piksel::dohvatiZelena() const
{
	return zelena;
}

int Piksel::dohvatiPlava() const
{
	return plava;
}

int Piksel::dohvatiY() const
{
	return y;
}

int Piksel::dohvatiX() const
{
	return x;
}

int Piksel::dohvatiProzirnost() const
{
	return prozirnost;
}

void Piksel::postaviProzirnost(int proz)
{
	prozirnost = proz;
}

void Piksel::postaviCrvenu(int crv)
{
	if (crv > 255)crv = 255;
	if (crv < 0) crv = 0;
	crvena = crv;
}

void Piksel::postaviZelenu(int zel)
{
	if (zel > 255)zel = 255;
	if (zel < 0) zel = 0;
	zelena = zel;
}

void Piksel::postaviPlavu(int pla)
{
	if (pla > 255)pla = 255;
	if (pla < 0) pla = 0;
	plava = pla;
}

std::ostream& operator<<(std::ostream& out, const Piksel& piksel)
{
	out << "(" << piksel.dohvatiCrvena() << "," << piksel.dohvatiZelena() << "," << piksel.dohvatiPlava()
		<< ")     ";
	return out;
}
