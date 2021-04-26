#include "henkilo.h"
#include "paivays.h"
#include "noppa.h"
#include "Osoite.h"
#include "Kalenterimerkinta.h"
#include <vector>
#include "Opettaja.h"
#include "Opiskelija.h"
#include "Koulu.h"

int main() {
	
	/*
	/////////////////////////////////////////////////////////////////////////
	//		Luodaan henkilo - vektori									/////
	/////////////////////////////////////////////////////////////////////////

	henkilo tyyppi;
	std::vector<henkilo*> lista;
	int valikko = 0;
	bool operand = true;
		do {
		std::cout << "Valitse vaihtoehto:" << std::endl;
		std::cout << "1 = Lisaa henkilo 2 = Tulosta henkilot 3 = Poista kayttajat 4 = Poista tietty kayttaja" << std::endl;
		std::cout << "Valintasi: ";
		std::cin >> valikko;
		// Luodaan uusi kaytt�j� 
		if (valikko == 1) {
			tyyppi.kysyTiedot();
			lista.push_back(new henkilo(tyyppi));
		}
		// tulostetaan vektorissa olemassa olevat k�ytt�j�t 
		else if (valikko == 2) {
			for (henkilo* h : lista) {
				h->tulostaHenkilonTiedot();
			}
		}
		// tyhjennet��n vektori sek� tyhjennet��n muistiosoitteet
		else if (valikko == 3) {
			lista.clear();
			for (henkilo* h : lista) {
				delete h;
			}
		}
		// tuhotaan haluttu k�ytt�j� jos l�ytyy, sek� sen pointteri
		else if (valikko == 4) {
			std::string syote;
			int index = 0;
			std::cin.clear();
			std::cin.ignore(80, '\n');
			std::cout << "Anna poistettavan henkilon nimi: ";
			std::getline(std::cin, syote);

			for (henkilo* h : lista) {
				if (h->getNimi() == syote){
					delete* (lista.begin() + index);
					lista.erase(lista.begin() + index);
					std::cout << "Henkilo poistettu" << std::endl;
				}
				index++;
			}
		}
		else
			operand = false;
	} while (operand);
	*/

	////////////////////////
	// Teht�v�t 1 ////////
	/////////////////////// 
	/*
	Opiskelija::Opiskelija(const std::string aNimi, const int& aIka, const Osoite& aOsoite, const int& aOpintopisteet)
	: henkilo (aNimi, aIka, aOsoite), opintopisteet(aOpintopisteet)
{
	std::cout << "Opiskelija-luokan parametrillinen rakentaja luotu." << std::endl;
	ika = 100;																			<----- onnistuu kun henkilo-luokassa muutetaan protectediksi, muutoin ei anna muuttaa nime� 
	nimi = "Mikko";																		   (T�ss� testattu Opiskelija-luokan rakentajassa asiaa)
}
	*/

	//////////////////////////////////////////////////
	//// Teht�v� 2-4 ///////////////////////////////

	Koulu tamk;
	tamk.setOpiskelija();
	tamk.setOpettaja();
	tamk.tulostaOpiskelija();
	tamk.tulostaOpettaja();
	tamk.tulostaKoulunTiedot();

	////////////////////////////////////////
	///// Teht�v� 5 ///////////////////////
	////////////////////////////////////////

	std::vector<henkilo*> lista;
	henkilo tyyppi;
	Opettaja ope;
	Opiskelija studentti;
	lista.push_back(new henkilo(tyyppi));
	lista.push_back(new Opettaja(ope));
	lista.push_back(new Opiskelija(studentti));






return 0;
}