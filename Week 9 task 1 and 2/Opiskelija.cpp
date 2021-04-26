#include "Opiskelija.h"

// rakentajat 
Opiskelija::Opiskelija() : opintopisteet (0)
{
	std::cout << "Opiskelija-oletusrakentaja luotu" << std::endl;
	kysyTiedot();
}

Opiskelija::Opiskelija(const std::string& aNimi, const int& aIka, const Osoite& aOsoite, const int& aOpintopisteet)
	: henkilo (aNimi, aIka, aOsoite), opintopisteet(aOpintopisteet)
{
	std::cout << "Opiskelija-luokan parametrillinen rakentaja luotu." << std::endl;
}

Opiskelija::Opiskelija(const Opiskelija& aOpiskelija)
	: opintopisteet(aOpiskelija.opintopisteet), kurssit(aOpiskelija.kurssit), henkilo(aOpiskelija.getNimi(), aOpiskelija.getIka(), aOpiskelija.getOsoite())
{
	std::cout << "Opiskelija-kopiorakentaja luotu" << std::endl;
}

Opiskelija::~Opiskelija()
{
	std::cout << "Opiskelija-luokan purkaja aktivoitu" << std::endl;
}

void Opiskelija::setOpintopisteet()
{
	bool temp = false;
	int kerroin;
	do{
	cinClear();
	std::cout << "Kuinka monen kurssin opintopisteet haluat lisata (Yhden kurssin pisteet ovat 3 pts)? Anna kurssien maara: ";
	std::cin >> kerroin;
	if (std::cin.fail()) {
		std::cout << "En tunnista syotetta" << std::endl;
		temp = true;
		}
	}while (temp);
	opintopisteet += (kerroin * 3);
}

void Opiskelija::setKurssi()
{
	std::string syote;
	std::cout << "Minka kurssin haluat lisata? Syota kurssi: " << std::endl;
	std::getline(std::cin, syote);
	kurssit.push_back(syote);
}

int Opiskelija::getPisteet() const
{
	return opintopisteet;
}

std::vector<std::string> Opiskelija::getKurssit() const
{
	return kurssit;
}

void Opiskelija::poistaKurssi()
{
	std::cin.clear();
	std::cin.ignore(100, '\n');
	bool operand = false;
	std::cout << std::endl;
	int index = 0;
	std::string syote;
	std::cout << "Minka kurssin haluat poistaa, syota kurssi: " << std::endl;
	std::getline(std::cin, syote);
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

void Opiskelija::poistaPisteita()
{
	bool operand = false;
	int temp;
	do {
		std::cout << "Kuinka monen kurssin pisteet haluat poistaa, syota kurssien maara: ";
		std::cin >> temp;
		if (std::cin.fail()) {
			std::cout << "En tunnista syotetta, syota uudelleen." << std::endl;
			operand = true;
		}
	} while (operand);
	opintopisteet -= (temp * 3);
}

void Opiskelija::tulostaTiedot() const
{
	std::cout << std::endl;
	std::cout << "Tulostetaan opiskelijan tiedot: " << std::endl <<std::endl;
	std::cout << "Ika: " << getIka() << std::endl;
	std::cout << "Nimi: " << getNimi() << std::endl;
	std::cout << "Osoite: ";
	getOsoite().tulostaTiedot();
	std::cout << "Opintopisteet: " << getPisteet() << std::endl;
	std::cout << "Kurssit: ";
	for (int i = 0; i < kurssit.size(); i++) {
		std::cout << kurssit[i] << " / ";
	}
	std::cout << std::endl << std::endl;
}



