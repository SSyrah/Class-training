#include "Opettaja.h"


Opettaja::Opettaja()
{
	std::cout << "Opettaja oletusrakentaja luotu." << std::endl;
	kysyTiedot();
}

Opettaja::Opettaja(const std::string& aNimi, const int& aIka, const Osoite& aOsoite, const std::string& aKoulutusala)
	: henkilo (aNimi, aIka, aOsoite), koulutusala (aKoulutusala)
{
	std::cout << "Opettaja parametrillinen rakentaja luotu." << std::endl;
}

Opettaja::~Opettaja()
{
	std::cout << "Opettaja-luokan purkaja aktivoitu" << std::endl;
}

void Opettaja::setKoulutusala(const std::string& aKoulutusala)
{
	koulutusala = aKoulutusala;
}

std::string Opettaja::getKoulutusala() const
{
	return koulutusala;
}

void Opettaja::lisaaKurssi()
{
	std::string syote;
	std::cout << "Minka kurssin haluat lisata? Syota kurssi: " << std::endl;
	std::getline(std::cin, syote);
	std::cin.clear();
	std::cin.ignore(60, '\n');
	kurssit.push_back(syote);
	std::cin.clear();
}

void Opettaja::poistaKurssi()
{
	std::cin.clear();
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

void Opettaja::tulostaOpettajanTiedot() const
{
	std::cout << "Tulostetaan opettajan tiedot: " << std::endl;
	tulostaHenkilonTiedot();
	std::cout << "Koulutusala: " << getKoulutusala() << std::endl;
	std::cout << "Kurssit: ";
	for (int i = 0; i < kurssit.size(); i++) {
		std::cout << kurssit[i] << "/";
	}
}
