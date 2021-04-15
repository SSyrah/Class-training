#pragma once
#include "henkilo.h"

class Opiskelija : public henkilo
{
public:
	
	Opiskelija();
	Opiskelija(const std::string aNimi, const int& aIka, const Osoite& aOsoite,  const int& aOpintopisteet);
	Opiskelija(const Opiskelija& aOpiskelija);
	~Opiskelija();

	void setOpintopisteet();
	void setKurssi();
	int getPisteet() const;
	std::vector<std::string> getKurssit() const;
	void poistaKurssi();
	void poistaPisteita();
	void tulostaOpiskelijanTiedot() const;

private:

	int opintopisteet;
	std::vector<std::string> kurssit;

};

