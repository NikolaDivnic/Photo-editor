#include "Pravougaonik.h"

Pravougaonik::Pravougaonik(int gor, int lev, int vis, int sir)
{
	if (lev < 0)lev = 0;
	if (gor < 0) gor = 0;
	if (sir < 0)sir = 0;
	if (vis < 0) vis = 0;
	levo = lev;
	gore = gor;
	sirina = sir;
	visina = vis;
}

int Pravougaonik::dohvatiSirinu() const
{
	return sirina;
}

int Pravougaonik::dohvatiVisinu() const
{
	return visina;
}

int Pravougaonik::dohvatiLevo() const
{
	return levo;
}

int Pravougaonik::dohvatiGore() const
{
	return gore;
}

