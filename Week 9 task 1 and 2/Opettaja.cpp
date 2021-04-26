#include "Opettaja.h"

// rakentajat

Opettaja::Opettaja()
{
	std::cout << "Opettaja oletusrakentaja luotu." << std::endl;
	kysyTiedot();
}

Opettaja::Opettaja(const std::string& aNimi, const int& aIka, const Osoite& aOsoite, const std::string& aKoulutusala)
	: henkilo(aNimi, aIka, aOsoite), koulutusala(aKoulutusala)
{
	std::cout << "Opettaja parametrillinen rakentaja luotu." << std::endl;
}

Opettaja::Opettaja(const Opettaja& aOpettaja)
	: koulutusala(aOpettaja.koulutusala), kurssit(aOpettaja.kurssit), henkilo(aOpettaja.getNimi(), aOpettaja.getIka(), aOpettaja.getOsoite())
{
	std::cout << "Opettaja-luokan kopiorakentaja luotu" << std::endl;
}

// purkaja
Opettaja::~Opettaja()
{
	std::cout << "Opettaja-luokan purkaja aktivoitu" << std::endl;
}

// funktiot 

void Opettaja::setKoulutusala(const std::string& aKoulutusala)
{
	koulutusala = aKoulutusala;
}

std::string Opettaja::getKoulutusala() const
{
	return koulutusala;
}

void Opettaja::setKurssi()
{
	std::string syote;
	std::cout << "Minka kurssin haluat lisata? Syota kurssi: " << std::endl;
	std::getline(std::cin, syote);
	kurssit.push_back(syote);
}

// kurssin poisto pienellä virheentarkistuksella

void Opettaja::poistaKurssi()
{
	cinClear();
	bool operand = false;
	std::cout << std::endl;
	int index = 0;
	std::string syote;
	std::cout << "Minka kurssin haluat poistaa, syota kurssi: " << std::endl;
	std::getline(std::cin, syote);
	std::cin.clear();
	std::cin.ignore(100, '\n');
	for (int i = 0; i < kurssit.size(); i++) {
		if (kurssit[i] == syote) {
			kurssit.erase(kurssit.begin() + index);
			std::cout << "Kurssi " << syote << " on poistettu." << std::endl;
			operand = true;
		}
		else {}
	index++;
	}
	if (operand == false)
		std::cout << "Ei loytynyt poistettavaa kurssia." << std::endl;
}

void Opettaja::tulostaTiedot() const
{
	std::cout << std::endl;
	std::cout << "Tulostetaan opettajan tiedot: " << std::endl << std::endl;
	std::cout << "Nimi: " << getNimi() << std::endl;
	std::cout << "Ika: " << getIka() << std::endl;
	std::cout << "Osoite: ";
	getOsoite().tulostaTiedot();
	std::cout << "Koulutusala: " << getKoulutusala() << std::endl;
	std::cout << "Kurssit: ";
	for (int i = 0; i < kurssit.size(); i++) {
		std::cout << kurssit[i] << "/";
	}
	std::cout << std::endl<<std::endl;
}
