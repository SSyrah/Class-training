#include "paivays.h"

// constuctors and destructors 

Paivays::Paivays() : paiva(0), kuukausi(0), vuosi(2000)
{
	std::cout << "Luodaan Paivays oletusrakentaja" << std::endl;
}

Paivays::Paivays(const int& aPaiva,const  int& aKuukausi, const int& aVuosi)
	: paiva(aPaiva), kuukausi(aKuukausi), vuosi(aVuosi)
{
	std::cout << "Luodaan 3-parametrinen rakentaja" << std::endl;
}

Paivays::~Paivays()
{
	std::cout << "Paivays-luokan purkaja aktivoitu" << std::endl;
}

// luokan metodien koodi alkaa tästä

void Paivays::setPaiva(int& aPaiva)
{
	if (aPaiva > 0 && aPaiva <= 31)
		paiva = aPaiva;
	else {
		std::cout << "Syotit liian suuren paivamaaaran, tulostetaan oletuksena nykyinen paivamaara." << std::endl;
		paiva = ltm->tm_mday;
	}
}

void Paivays::setKuukausi(int& aKuukausi)
{
	if (aKuukausi > 0 && aKuukausi < 13)
		kuukausi = aKuukausi;
	else {
		std::cout << "Syotit liian suuren tai pienen kuukauden, tulostetaan nykyinen kuukausi oletuksena" << std::endl;
		kuukausi = 1 + ltm->tm_mon;
	}
}

void Paivays::setVuosi(int& aVuosi)
{
	if (aVuosi > 0 && aVuosi <= 1900 + ltm->tm_year + 10)
		vuosi = aVuosi;
	else {
		std::cout << "Syotit liian suuren vuoden (voit laittaa muistutuksen vain 10 vuoden paahan), asetetaan nykyinen vuosi" << std::endl;
		vuosi = 1900 + ltm->tm_year;
	}
}


int Paivays::getPaiva() const
{
	return paiva;
}

int Paivays::getKuukausi() const
{
	return kuukausi;
}

int Paivays::getVuosi() const
{
	return vuosi;
}


void Paivays::tulostaPaivaysTanaan() const
{
	std::cout << paiva << "." << kuukausi << "." << vuosi << std::endl;
}
void Paivays::tulostaPaivaysHuomenna() const
{
	if (kuukausi == 1 || kuukausi == 3 || kuukausi == 5 || kuukausi == 7 || kuukausi == 8 || kuukausi == 10 || kuukausi == 12) {
		if (paiva < 31) {
			std::cout << paiva + 1 << "." << kuukausi << "." << vuosi;
		}
		else {
			std::cout << paiva - 31 + 1 << "." << kuukausi + 1 << "." << vuosi;
		}
	}
	else if (kuukausi == 2) {
		if (paiva < 28) {
			std::cout << paiva + 1 << "." << kuukausi << "." << vuosi;
		}
		else {
			std::cout << paiva - 28 + 1 << "." << kuukausi + 1 << "." << vuosi;
		}
	}
	else {
		if (paiva < 30) {
			std::cout << paiva + 1 << "." << kuukausi << "." << vuosi;
		}
		else {
			std::cout << paiva - 30 + 1 << "." << kuukausi + 1 << "." << vuosi;
		}
	}
}

void Paivays::kysyPaivays()
{
	int pv, kk, vv;
	std::cout << "Anna paivamaara, ensin vuosi: ";
	std::cin >> vv;
	std::cout << "kuukausi: ";
	std::cin >> kk;
	std::cout << "paiva: ";
	std::cin >> pv;
	setVuosi(vv);
	setKuukausi(kk);
	setPaiva(pv);
}

void Paivays::kasvataPaivaysta()
{
	if (paiva < 31) {
		paiva++;
	}
	else {
		paiva = 1;
		kuukausi++;
	}
}

int Paivays::tarkistaKuukausi(int& aSyote)
{
	if (kuukausi == 4 || kuukausi == 6 || kuukausi == 9 || kuukausi == 11) {
		return 30;
	}
	else if (kuukausi == 2) {//helmikuu
		if (vuosi % 4 == 0) {
			return 29;
		}
		return 28;
	}
	return 31;
}

