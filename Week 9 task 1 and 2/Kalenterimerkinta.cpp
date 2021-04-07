#include "Kalenterimerkinta.h"

// constuctors and destructors 

Kalenterimerkinta::Kalenterimerkinta() : asia("---"), muistutus(false)
{
	std::cout << "kalenteri-luokan oletusrakentaja aktivoitu" << std::endl;
}

Kalenterimerkinta::Kalenterimerkinta(const std::string& aAsia, bool& aMuistutus, const Paivays& aPaivays)
	:asia(aAsia), muistutus(false), paivays(aPaivays)
{
	std::cout << "Kalenteri-luokan parametrillinen rakentaja aktivoitu." << std::endl;
}

Kalenterimerkinta::Kalenterimerkinta(const Kalenterimerkinta& aKalenterimerkinta)
	:asia(aKalenterimerkinta.asia), muistutus(aKalenterimerkinta.muistutus)
{
	std::cout << "Kalenterimerkinta - Kopiorakentaja aktivoitu" << std::endl;
	paivays.kysyPaivays();
}

Kalenterimerkinta::~Kalenterimerkinta()
{
	std::cout << "Kalenteri-luokan purkaja aktivoitu" << std::endl;
}

void Kalenterimerkinta::kysyTiedot()
{
	std::string syote;
	std::cout <<"Anna kalenterimerkinta: ";
	std::getline(std::cin, asia);
	std::cout << "Laitetaanko muistutus? (K/E)";
	std::getline(std::cin, syote);
	if (syote == "K" || syote == "k") {
		muistutus = true;
		}
	else {
		muistutus = false;
	}
	paivays.kysyPaivays();
}

std::string Kalenterimerkinta::getAsia() const
{
	return asia;
}

bool Kalenterimerkinta::getMuistutus() const
{
	return muistutus;
}

void Kalenterimerkinta::setAsia(const std::string& aAsia)
{
	asia = aAsia;
}

void Kalenterimerkinta::setMuistutus(bool& aMuistutus)
{
	muistutus = aMuistutus;
}

void Kalenterimerkinta::tulostaKalenterimerkinta() const
{
	std::cout << "Asetit seuraavanlaisen kalenterimerkinnan: " << std::endl;
	std::cout << "Paivays: ";
	paivays.tulostaPaivaysTanaan();
	std::cout << "Asettamasi merkinta: " << asia << std::endl;
	std::cout << "Muistutus laitettu: ";
	if (muistutus)
		std::cout << "Kylla" << std::endl << std::endl;
	else
		std::cout << "Ei" << std::endl << std::endl;
	
}

