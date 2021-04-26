#include "Koulu.h"

Koulu::Koulu() : koulunNimi("TAMK")
{
	std::cout << "Koulu-luokan oletusrakentaja aktivoitu" << std::endl;
}

Koulu::Koulu(const std::string& akoulunNimi, const Opettaja& aOpettajat, const Opiskelija& aOpiskelijat) 
	: koulunNimi(akoulunNimi)
{
	std::cout << "Koulu-luokan parametrillinen rakentaja aktivoitu" << std::endl;
}

Koulu::~Koulu()
{
	std::cout << "Koulu-luokan purkaja aktivoitu" << std::endl;
}

void Koulu::setOpiskelija()
{
	std::cout << "Syota opiskelijan tiedot: " << std::endl;
	Opiskelija temp;
	temp.setKurssi();
	Opiskelijat.push_back(new Opiskelija(temp));
}

void Koulu::setOpettaja()
{
	Opettaja temp;
	temp.setKurssi();
	Opettajat.push_back(new Opettaja(temp));
}

void Koulu::tulostaOpiskelija() const
{
	for (Opiskelija* h : Opiskelijat) {
		h->tulostaTiedot();
		std::cout << "\n\n";
	}
}

void Koulu::tulostaOpettaja() const
{
	for (Opettaja* o : Opettajat) {
		o->tulostaTiedot();
		std::cout << "\n\n";
	}
}

void Koulu::tulostaKoulunTiedot() const
{
	std::cout << std::setw(8) << "Tulostetaan koulun tiedot: " << std::endl;
	std::cout << std::setw(3) << "Koulun nimi: " << koulunNimi << std::endl;
	std::cout << std::setw(3) << "Opettajien lukumaara: ";
	int index = 0, index2 = 0;
	for (Opettaja* o : Opettajat) {
		index++;
	}
	std::cout << index << std::endl;
	std::cout << std::setw(3) << "Opiskelijoiden lukumaara: ";
	for (Opiskelija* h : Opiskelijat) {
		index2++;
	}
	std::cout << index2 << std::endl;
	std::cout << std::setw(8) << "Opettajien tiedot: " << std::endl;
	tulostaOpettaja();
	std::cout << std::setw(8) << "Opiskelijoiden tiedot: " << std::endl;
	tulostaOpiskelija();
}

std::vector<Opiskelija*> Koulu::getOpiskelijat() const
{
	return Opiskelijat;
}

std::vector<Opettaja*> Koulu::getOpettajat() const
{
	return Opettajat;
}
