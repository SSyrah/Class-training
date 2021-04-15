#pragma once
#include "henkilo.h"
class Opettaja : public henkilo
{
public:
	Opettaja();
	Opettaja(const std::string& aNimi, const int& aIka, const Osoite& aOsoite, const std::string& aKoulutusala);
	Opettaja(const Opettaja& aOpettaja);
	~Opettaja();

	void setKoulutusala(const std::string& aKoulutusala);
	std::string getKoulutusala() const;
	void setKurssi();
	void poistaKurssi();
	void tulostaOpettajanTiedot() const;

private:
	std::string koulutusala;
	std::vector<std::string> kurssit;
};

