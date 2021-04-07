#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "paivays.h"


class Kalenterimerkinta
{
public:
	Kalenterimerkinta();
	Kalenterimerkinta(const std::string& aAsia, bool& aMuistutus, const Paivays& aPaivays);
	//Luodaan kopiorakentaja
	Kalenterimerkinta(const Kalenterimerkinta& aKalenterimerkinta);

	~Kalenterimerkinta();

	void kysyTiedot();
	std::string getAsia()const;
	bool getMuistutus() const;
	void setAsia(const std::string& aAsia);
	void setMuistutus(bool& aMuistutus);
	void tulostaKalenterimerkinta() const;

private:
	std::string asia;
	bool muistutus;
	Paivays paivays;

};

