#include "SlozenaOperacija.h"

SlozenaOperacija& SlozenaOperacija::dodajOperaciju(std::shared_ptr<Operacija> o)
{
	operacije.push_back(o);
	return *this;
}

int SlozenaOperacija::dohvatiBrojOperacija() const {
	return operacije.size();
}

SlozenaOperacija& SlozenaOperacija::skloniOperaciju(int i)
{
	if (i < 0 || i >=(int) operacije.size())
		throw Granice();
	operacije.erase(operacije.begin() + i);
	return *this;
}

void SlozenaOperacija::izvrsi(Slika& slika)
{
	for (int i = 0; i <(int) operacije.size(); i++) {
		operacije[i]->izvrsi(slika);
	}
}

char SlozenaOperacija::vrsta() const
{
	return 's';
}

std::shared_ptr<Operacija> SlozenaOperacija::dohvatiOperaciju(int i) {
	if (i < 0 || i >=(int) operacije.size())
		throw Granice();
	return operacije[i];
}

std::ostream& SlozenaOperacija::ispisiUFormat(std::ostream& fajl) {
	fajl << "<slozenaOperacija>" << "\n<brojOperacija>" << dohvatiBrojOperacija() << "</brojOperacija>\n";
	for (int i = 0; i < dohvatiBrojOperacija(); i++) {
		dohvatiOperaciju(i)->ispisiUFormat(fajl);
	}
	fajl << "</slozenaOperacija>\n";
	return fajl;
}

