#include "henkilo.h"
#include "paivays.h"
#include "noppa.h"
#include "Osoite.h"
#include "Kalenterimerkinta.h"
#include <vector>
#include "Opettaja.h"

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
		// Luodaan uusi kayttäjä 
		if (valikko == 1) {
			tyyppi.kysyTiedot();
			lista.push_back(new henkilo(tyyppi));
		}
		// tulostetaan vektorissa olemassa olevat käyttäjät 
		else if (valikko == 2) {
			for (henkilo* h : lista) {
				h->tulostaHenkilonTiedot();
			}
		}
		// tyhjennetään vektori sekä tyhjennetään muistiosoitteet
		else if (valikko == 3) {
			lista.clear();
			for (henkilo* h : lista) {
				delete h;
			}
		}
		// tuhotaan haluttu käyttäjä jos löytyy, sekä sen pointteri
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

	Opettaja ope;
	ope.setKoulutusala("Tietotekniikka");
	ope.lisaaKurssi();
	ope.lisaaKurssi();
	ope.tulostaOpettajanTiedot();
	ope.poistaKurssi();
	ope.tulostaOpettajanTiedot();


	std::cout << std::endl << std::endl;
	std::cout << "Ohjelma paattynyt" << std::endl;

	


return 0;
}