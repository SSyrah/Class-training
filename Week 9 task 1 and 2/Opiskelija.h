#pragma once
#include "henkilo.h"
class Opiskelija : public henkilo
{
public:
	
	Opiskelija();
	Opiskelija(const std::string aNimi, const int& aIka, const Osoite& aOsoite, const std::vector<std::string> aKurssit, const int& pisteet);
	~Opiskelija();

	void setOpintopisteet();
	void setKurssi();
	int getPisteet();
	void poistaKurssi();
	void poistaPisteita();
	void tulostaOpiskelijanTiedot();

private:

	int opintopisteet;
	std::vector<std::string> kurssit;

};

