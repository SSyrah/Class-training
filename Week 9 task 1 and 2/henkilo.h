#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Osoite.h"


// Henkilö - luokan esittely (kirjoitetaan omaan .h-tiedostoon

class henkilo
{
	// luokan julkinen rajapinta (API), toiminnot, metodit
public:
	//Constuctors:
	henkilo();
	henkilo(const std::string& aNimi, const int& aIka);
	henkilo(const std::string& aNimi, const int& aIka, const Osoite& aOsoite);
	//Copy Constructor
	henkilo(const henkilo& aHenkilo);

	//Destructors:
	~henkilo();

	void kysyTiedot();
	void setNimi(const std::string& aNimi);
	void setIka(const int& aIka);
	int getIka() const;
	std::string getNimi() const;
	/* virtual */  void tulostaTiedot() const;
	void kasva();

	Osoite getOsoite() const;
	void setOsoite(const Osoite& aOsoite);


	// Luokan tietojäsenet, yksityinen osuus (yleesä private)
	// Näihin päästään käsiksi vain luokan metodeissa
private:
	
	std::string nimi;
	int ika;
	Osoite osoite;
};

void cinClear();