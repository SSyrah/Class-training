#include "henkilo.h"
#include "Osoite.h"
#include <istream>


// Henkilö - luokan määrittely eli toteutus (implementation)


henkilo::henkilo() : nimi("---"), ika(0)
{
	std::cout << "Luodaan henkilo-luokan parametriton rakentaja" << std::endl;
}

henkilo::henkilo(const std::string& aNimi, const int& aIka) : nimi(aNimi), ika(aIka)
{
	std::cout << "Luodaan 3-parametrinen henkilo-rakentaja" << std::endl;
}

henkilo::henkilo(const std::string& aNimi, const int& aIka, const Osoite& aOsoite)
	: nimi (aNimi), ika(aIka), osoite(aOsoite)
{
	std::cout << "henkilo-rakentaja osoite-luokan kanssa aktivoitu" << std::endl;
}

henkilo::henkilo(const henkilo& aHenkilo)
	:nimi(aHenkilo.nimi),ika(aHenkilo.ika)
{
	std::cout << "Henkilo-luokan kopiorakentaja aktivoitu" << std::endl;
}

henkilo::~henkilo()
{
	std::cout << "Henkilo-luokan purkaja aktivoitu" << std::endl;
}

void henkilo::kysyTiedot()
{
	std::cout<< std::endl;
	std::cout << "Anna nimi: ";
	std::getline(std::cin, nimi);
	std::cout << "Anna ika: ";
	std::cin >> ika;
	std::cin.ignore(80, '\n');
	osoite.kysyOsoitetiedot();
}

void henkilo::setNimi(const std::string& aNimi) {
	// asetetaan henkilölle nimi
	nimi = aNimi;
}

void henkilo::setIka(const int& aIka)
{
	ika = aIka;
}

int henkilo::getIka() const
{
	return ika;
}

std::string henkilo::getNimi() const
{
	return nimi;
}

void henkilo::tulostaTiedot() const
{
	std::cout << std::endl;
	std::cout << "Henkilon tiedot: " << std::endl;
	std::cout << "Nimi: " << nimi << std::endl;
	std::cout << "Ika: " << ika << std::endl;
	osoite.tulostaTiedot();
}

void henkilo::kasva()
{
	ika++;
}

Osoite henkilo::getOsoite() const
{
	return osoite;
}

void henkilo::setOsoite(const Osoite& aOsoite)
{
	osoite = aOsoite;
}

void cinClear()
{
	std::cin.clear();
	std::cin.ignore(100, '\n');
}
