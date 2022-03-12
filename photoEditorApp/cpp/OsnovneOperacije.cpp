#include "OsnovneOperacije.h"
#include"Slika.h"
void OsnovneOperacije::sabiranje(std::shared_ptr<Piksel> p)
{
	if (boja == "crvena") p->postaviCrvenu(p->dohvatiCrvena() + con);
	else if (boja == "zelena") p->postaviZelenu(p->dohvatiZelena() + con);
	else if (boja == "plava") p->postaviPlavu(p->dohvatiPlava() + con);
	else if (boja == "sve")
		p->postaviBoju(
			p->dohvatiCrvena() + con,
			p->dohvatiZelena() + con,
			p->dohvatiPlava() + con);
		else throw NepravilnaBoja();
}

void OsnovneOperacije::oduzimanje(std::shared_ptr<Piksel> p)
{
	con = -con;
	sabiranje(p);
	con = -con;
}

void OsnovneOperacije::inverznoOduzimanje(std::shared_ptr<Piksel> p)
{
	if (boja == "crvena") p->postaviCrvenu(con - p->dohvatiCrvena());
	else if (boja == "zelena") p->postaviZelenu(con - p->dohvatiZelena());
	else if (boja == "plava") p->postaviPlavu(con - p->dohvatiPlava());
	else if (boja == "sve")
		p->postaviBoju(
			con - p->dohvatiCrvena(),
			con - p->dohvatiZelena(),
			con - p->dohvatiPlava());
		else throw NepravilnaBoja();
}

void OsnovneOperacije::mnozenje(std::shared_ptr<Piksel> p)
{
	if (boja == "crvena") p->postaviCrvenu(p->dohvatiCrvena() * con);
	else if (boja == "zelena") p->postaviZelenu(p->dohvatiZelena() * con);
	else if (boja == "plava") p->postaviPlavu(p->dohvatiPlava() * con);
	else if (boja == "sve")
		p->postaviBoju(
			p->dohvatiCrvena() * con,
			p->dohvatiZelena() * con,
			p->dohvatiPlava() * con);
		else throw NepravilnaBoja();
}

void OsnovneOperacije::deljenje(std::shared_ptr<Piksel> p)
{
	if (boja == "crvena") p->postaviCrvenu(p->dohvatiCrvena() / con);
	else if (boja == "zelena") p->postaviZelenu(p->dohvatiZelena() / con);
	else if (boja == "plava") p->postaviPlavu(p->dohvatiPlava() / con);
	else if (boja == "sve")
	p->postaviBoju(
		p->dohvatiCrvena() / con,
		p->dohvatiZelena() / con,
		p->dohvatiPlava() / con);
		else throw NepravilnaBoja();

}

void OsnovneOperacije::inverznoDeljenje(std::shared_ptr<Piksel> p)
{
	if (boja == "crvena") p->postaviCrvenu((int)con / p->dohvatiCrvena());
	else if (boja == "zelena") p->postaviZelenu((int)con / p->dohvatiZelena());
	else if (boja == "plava") p->postaviPlavu((int)con/p->dohvatiPlava());
	else if (boja == "sve")
	p->postaviBoju(
		(int)con / p->dohvatiCrvena(),
		(int)con / p->dohvatiZelena(),
		(int)con/p->dohvatiPlava());
		else throw NepravilnaBoja();
}

void OsnovneOperacije::power(std::shared_ptr<Piksel> p)
{
	if (boja == "crvena") p->postaviCrvenu((int)pow(p->dohvatiCrvena(), con));
	else if (boja == "zelena") p->postaviZelenu((int)pow(p->dohvatiZelena(), con));
	else if (boja == "plava") p->postaviPlavu((int)pow(p->dohvatiPlava(), con));
	else if (boja == "sve")
	p->postaviBoju(
		(int)pow(p->dohvatiCrvena(), con),
		(int)pow(p->dohvatiZelena(), con),
		(int)pow(p->dohvatiPlava(), con));
	else throw NepravilnaBoja();
}

void OsnovneOperacije::log(std::shared_ptr<Piksel> p)
{
	int p1 = con, br1 = 0, br2 = 0, br3 = 0;
	while (p->dohvatiCrvena() >= p1) {
		p1 *= con;
		br1++;
	}
	p1 = con;
	while (p->dohvatiCrvena() >= p1) {
		p1 *= con;
		br2++;
	}
	p1 = con;
	while (p->dohvatiCrvena() >= p1) {
		p1 *= con;
		br3++;
	}
	if (boja == "crvena") p->postaviCrvenu(br1);
	else if (boja == "zelena") p->postaviZelenu(br2);
	else if (boja == "plava") p->postaviPlavu(br3);
	else if (boja == "sve")
		p->postaviBoju(br1, br2, br3);
	else throw NepravilnaBoja();

}

void OsnovneOperacije::abs(std::shared_ptr<Piksel> p)
{
	int pomC = p->dohvatiCrvena(), pomP = p->dohvatiPlava(), pomZ = p->dohvatiZelena();
	if (pomC < con)pomC += 2 * (con - pomC);
	if (pomZ < con)pomZ += 2 * (con - pomZ);
	if (pomP < con)pomP += 2 * (con - pomP);
	if (boja == "crvena") p->postaviCrvenu(pomC);
	else if (boja == "zelena") p->postaviZelenu(pomZ);
	else if (boja == "plava") p->postaviPlavu(pomP);
	else if (boja == "sve")
		p->postaviBoju(pomC, pomZ, pomP);
	else throw NepravilnaBoja();
}

void OsnovneOperacije::min(std::shared_ptr<Piksel> p)
{
	int pomC = p->dohvatiCrvena(), pomP = p->dohvatiPlava(), pomZ = p->dohvatiZelena();
	if (pomC < con)pomC = con;
	if (pomZ < con)pomZ = con;
	if (pomP < con)pomP = con;
	if (boja == "crvena") p->postaviCrvenu(pomC);
	else if (boja == "zelena") p->postaviZelenu(pomZ);
	else if (boja == "plava") p->postaviPlavu(pomP);
	else if (boja == "sve")
		p->postaviBoju(pomC, pomZ, pomP);
	else throw NepravilnaBoja();

}

void OsnovneOperacije::max(std::shared_ptr<Piksel> p)
{
	int pomC = p->dohvatiCrvena(), pomP = p->dohvatiPlava(), pomZ = p->dohvatiZelena();
	if (pomC > con)pomC = con;
	if (pomZ > con)pomZ = con;
	if (pomP > con)pomP = con;
	if (boja == "crvena") p->postaviCrvenu(pomC);
	else if (boja == "zelena") p->postaviZelenu(pomZ);
	else if (boja == "plava") p->postaviPlavu(pomP);
	else if (boja == "sve")
		p->postaviBoju(pomC, pomZ, pomP);
}

void OsnovneOperacije::negacijaBoje(std::shared_ptr<Piksel> p)
{
	con = 255;
	inverznoOduzimanje(p);
}

void OsnovneOperacije::pretvaranjeUSivu(std::shared_ptr<Piksel> p)
{
	int pomC = p->dohvatiCrvena(), pomP = p->dohvatiPlava(), pomZ = p->dohvatiZelena();
	int pom = (pomC + pomZ + pomP) / 3;
	p->postaviBoju(pom, pom, pom);
}

void OsnovneOperacije::pretvaranjeUCrnoBelu(std::shared_ptr<Piksel> p)
{
	int pomC = p->dohvatiCrvena(), pomP = p->dohvatiPlava(), pomZ = p->dohvatiZelena();
	int pom = (pomC + pomZ + pomP) / 3;
	if (pom < 127) pom = 0;
	else pom = 255;
	p->postaviBoju(pom, pom, pom);

}

OsnovneOperacije::OsnovneOperacije(OPERACIJE o, std::string im)
{
	if (im != "crvena" && im != "zelena" && im != "plava" && im != "sve")
		throw NepravilnaBoja();
	if (o == PLUS || o == MINUS || o == INVERZNOODUZIMANJE || o == MNOZENJE || o == DELJENJE ||
		o == INVERZNODELJENJE || o == POWER || o == LOG || o == ABS || o == MIN || o == MAX)
		throw LosaOperacija();
	operacija = o;
	boja = im;
	con = 0;
	
}

OsnovneOperacije::OsnovneOperacije(OPERACIJE o, std::string im, int c)
{
	if (im != "crvena" && im != "zelena" && im != "plava" && im != "sve")
		throw NepravilnaBoja();
	con = c;
	boja = im;
	operacija = o;
}

void OsnovneOperacije::izvrsi(Slika& slika)
{
	if (slika.imaAktivnaSelekcija()) {
		std::shared_ptr<Selekcija> selekcija = slika.dohvatiAktivnuSelekciju();
		std::vector<std::vector<bool>> obradjeniPikseli(slika.dohvatiSloj(0)->dohvatiDodataVisina());
		for (int i = 0; i < slika.dohvatiSloj(0)->dohvatiDodataVisina(); i++) {
			obradjeniPikseli[i].resize(slika.dohvatiSloj(0)->dohvatiDodataSirina());
			for (int j = 0; j < slika.dohvatiSloj(0)->dohvatiDodataSirina(); j++) {
				obradjeniPikseli[i][j] = false;
			}
		}
		bool promena = false;
		for (std::shared_ptr<Pravougaonik> p : selekcija->dohvatiPravougaonike()) {
			for (int i = 0; i < p->dohvatiVisinu(); i++) {
				for (int j = 0; j < p->dohvatiSirinu(); j++) {
					for (int  k = 0; k < slika.brojSlojeva(); k++) {
						if (slika.dohvatiSloj(k)->dohvatiAktivna()) {

							if (!obradjeniPikseli[i+p->dohvatiGore()][j+ p->dohvatiLevo()] && slika.dohvatiSloj(k)->daLiJePikselUTomSloju(i + p->dohvatiGore(),j + p ->dohvatiLevo())) {
								switch (operacija)
								{
								case PLUS:
									sabiranje(slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo())); promena = true; break;
								case MINUS:
									oduzimanje(slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo())); promena = true; break;
								case INVERZNOODUZIMANJE:
									inverznoOduzimanje(slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo())); promena = true; break;
								case MNOZENJE:
									mnozenje(slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo())); promena = true; break;
								case DELJENJE:
									deljenje(slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo())); promena = true; break;
								case INVERZNODELJENJE:
									inverznoDeljenje(slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo())); promena = true; break;
								case POWER:
									power(slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo())); promena = true; break;
								case LOG:
									log(slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo())); promena = true; break;
								case ABS:
									abs(slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo())); promena = true; break;
								case MIN:
									min(slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo())); promena = true; break;
								case MAX:
									max(slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo()));  promena = true; break;
								case NEGACIJABOJE:
									negacijaBoje(slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo()));  promena = true; break;
								case PRETVARANJEUSIVU:
									pretvaranjeUSivu(slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo()));  promena = true; break;
								case PRETVARANJEUCRNOBELU:
									pretvaranjeUCrnoBelu(slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo())); promena = true; break;
								case MEDIJANA:
								{
									std::shared_ptr<Piksel> pp = slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo());
									int broj = 1;
									int pomC = pp->dohvatiCrvena(), pomP = pp->dohvatiPlava(), pomZ = pp->dohvatiZelena();
									if (slika.dohvatiSloj(k)->daLiJePikselUTomSloju(i + p->dohvatiGore() - 1, j + p->dohvatiLevo())) {
										std::shared_ptr<Piksel> pp2 = slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore() - 1, j + p->dohvatiLevo());
										pomC += pp2->dohvatiCrvena();
										pomP += pp2->dohvatiPlava();
										pomZ += pp2->dohvatiZelena();
										broj++;
									}
									if (slika.dohvatiSloj(k)->daLiJePikselUTomSloju(i + p->dohvatiGore() + 1, j + p->dohvatiLevo())) {
										std::shared_ptr<Piksel> pp2 = slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore() + 1, j + p->dohvatiLevo());
										pomC += pp2->dohvatiCrvena();
										pomP += pp2->dohvatiPlava();
										pomZ += pp2->dohvatiZelena();
										broj++;
									}
									if (slika.dohvatiSloj(k)->daLiJePikselUTomSloju(i + p->dohvatiGore(), j + p->dohvatiLevo() - 1)) {
										std::shared_ptr<Piksel> pp2 = slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo() - 1);
										pomC += pp2->dohvatiCrvena();
										pomP += pp2->dohvatiPlava();
										pomZ += pp2->dohvatiZelena();
										broj++;
									}
									if (slika.dohvatiSloj(k)->daLiJePikselUTomSloju(i + p->dohvatiGore(), j + p->dohvatiLevo() + 1)) {
										std::shared_ptr<Piksel> pp2 = slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo() + 1);
										pomC += pp2->dohvatiCrvena();
										pomP += pp2->dohvatiPlava();
										pomZ += pp2->dohvatiZelena();
										broj++;
									}
									pomC = (int)pomC / broj;
									pomZ = (int)pomZ / broj;
									pomP = (int)pomP / broj;
									if (boja == "crvena") slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo())->postaviCrvenu(pomC);
									else if (boja == "zelena") slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo())->postaviZelenu(pomZ);
									else if (boja == "plava")slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo())->postaviPlavu(pomP);
									else if (boja == "sve")
										slika.dohvatiSloj(k)->dohvatiPiskel(i + p->dohvatiGore(), j + p->dohvatiLevo())->postaviBoju(pomC, pomZ, pomP);
									break;
								}
								default:
									break;
								}
								
							}
						}
						
					}
					if (promena) {
						obradjeniPikseli[i + p->dohvatiGore()][j + p->dohvatiLevo()] = true;
						promena = false;
					}
						
				}
			}

		}
	}


	else {
		for (int i = 0; i < slika.dohvatiSloj(0)->dohvatiDodataVisina(); i++) {
			for (int j = 0; j < slika.dohvatiSloj(0)->dohvatiDodataSirina(); j++) {
				for (int k = 0; k < slika.brojSlojeva(); k++) {
					if (slika.dohvatiSloj(k)->dohvatiAktivna()&&(i < slika.dohvatiSloj(k)->dohvatiGore() + slika.dohvatiSloj(k)->dohvatiVisinu()) 
						&& i >= slika.dohvatiSloj(k)->dohvatiGore()
						&& (j < slika.dohvatiSloj(k)->dohvatiLevo() + slika.dohvatiSloj(k)->dohvatiSirinu()) && j >= slika.dohvatiSloj(k)->dohvatiLevo()) {

						
							switch (operacija)
							{
							case PLUS:
								sabiranje(slika.dohvatiSloj(k)->dohvatiPiskel(i, j)); break;
							case MINUS:
								oduzimanje(slika.dohvatiSloj(k)->dohvatiPiskel(i, j)); break;
							case INVERZNOODUZIMANJE:
								inverznoOduzimanje(slika.dohvatiSloj(k)->dohvatiPiskel(i, j)); break;
							case MNOZENJE:
								mnozenje(slika.dohvatiSloj(k)->dohvatiPiskel(i, j)); break;
							case DELJENJE:
								deljenje(slika.dohvatiSloj(k)->dohvatiPiskel(i, j)); break;
							case INVERZNODELJENJE:
								inverznoDeljenje(slika.dohvatiSloj(k)->dohvatiPiskel(i, j)); break;
							case POWER:
								power(slika.dohvatiSloj(k)->dohvatiPiskel(i, j)); break;
							case LOG:
								log(slika.dohvatiSloj(k)->dohvatiPiskel(i, j)); break;
							case ABS:
								abs(slika.dohvatiSloj(k)->dohvatiPiskel(i, j)); break;
							case MIN:
								min(slika.dohvatiSloj(k)->dohvatiPiskel(i, j)); break;
							case MAX:
								max(slika.dohvatiSloj(k)->dohvatiPiskel(i, j)); break;
							case NEGACIJABOJE:
								negacijaBoje(slika.dohvatiSloj(k)->dohvatiPiskel(i, j)); break;
							case PRETVARANJEUSIVU:
								pretvaranjeUSivu(slika.dohvatiSloj(k)->dohvatiPiskel(i, j)); break;
							case PRETVARANJEUCRNOBELU:
								pretvaranjeUCrnoBelu(slika.dohvatiSloj(k)->dohvatiPiskel(i, j)); break;
							case MEDIJANA:
							{
								std::shared_ptr<Piksel> pp = slika.dohvatiSloj(k)->dohvatiPiskel(i, j );
								int broj = 1;
								int pomC = pp->dohvatiCrvena(), pomP = pp->dohvatiPlava(), pomZ = pp->dohvatiZelena();
								if (slika.dohvatiSloj(k)->daLiJePikselUTomSloju(i  - 1, j )) {
									std::shared_ptr<Piksel> pp2 = slika.dohvatiSloj(k)->dohvatiPiskel(i  - 1, j );
									pomC += pp2->dohvatiCrvena();
									pomP += pp2->dohvatiPlava();
									pomZ += pp2->dohvatiZelena();
									broj++;
								}
								if (slika.dohvatiSloj(k)->daLiJePikselUTomSloju(i  + 1, j )) {
									std::shared_ptr<Piksel> pp2 = slika.dohvatiSloj(k)->dohvatiPiskel(i  + 1, j );
									pomC += pp2->dohvatiCrvena();
									pomP += pp2->dohvatiPlava();
									pomZ += pp2->dohvatiZelena();
									broj++;
								}
								if (slika.dohvatiSloj(k)->daLiJePikselUTomSloju(i , j - 1)) {
									std::shared_ptr<Piksel> pp2 = slika.dohvatiSloj(k)->dohvatiPiskel(i , j  - 1);
									pomC += pp2->dohvatiCrvena();
									pomP += pp2->dohvatiPlava();
									pomZ += pp2->dohvatiZelena();
									broj++;
								}
								if (slika.dohvatiSloj(k)->daLiJePikselUTomSloju(i , j + 1)) {
									std::shared_ptr<Piksel> pp2 = slika.dohvatiSloj(k)->dohvatiPiskel(i , j  + 1);
									pomC += pp2->dohvatiCrvena();
									pomP += pp2->dohvatiPlava();
									pomZ += pp2->dohvatiZelena();
									broj++;
								}
								pomC = (int)pomC / broj;
								pomZ = (int)pomZ / broj;
								pomP = (int)pomP / broj;
								if (boja == "crvena") slika.dohvatiSloj(k)->dohvatiPiskel(i , j )->postaviCrvenu(pomC);
								else if (boja == "zelena") slika.dohvatiSloj(k)->dohvatiPiskel(i, j )->postaviZelenu(pomZ);
								else if (boja == "plava")slika.dohvatiSloj(k)->dohvatiPiskel(i , j )->postaviPlavu(pomP);
								else if (boja == "sve")
									slika.dohvatiSloj(k)->dohvatiPiskel(i , j)->postaviBoju(pomC, pomZ, pomP);
								break;
							}
							default:
								break;
							}
						
					}
				}
			}
		}


	}

}

char OsnovneOperacije::vrsta() const
{
	return 'o';
}

int OsnovneOperacije::dohvatiOperaciju() const {
	return (int)operacija;
}

std::string OsnovneOperacije::dohvatiBoju() const {
	return boja;
}

int OsnovneOperacije::dohvatiKonstantu() const {
	return con;
}

std::ostream& OsnovneOperacije::ispisiUFormat(std::ostream& fajl)
{
	fajl << "<osnovnaOperacija>"<<"\n\t<operacija>" << dohvatiOperaciju() << "</operacija>\n\t<boja>" <<dohvatiBoju()
		<< "</boja>\n\t<konstanta>" << dohvatiKonstantu() << "</konstanta>\n"<<"</osnovnaOperacija>\n";
	return fajl;
}


