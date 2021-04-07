#include "henkilo.h"
#include "paivays.h"
#include "noppa.h"
#include "Osoite.h"
#include "Kalenterimerkinta.h"
#include <vector>



void doSomethingArvoparametri (Kalenterimerkinta aKalenterimerkinta)
{
	aKalenterimerkinta.setAsia("ei tapahtumia");
	aKalenterimerkinta.tulostaKalenterimerkinta();
	return;
}

void doSomethingViittausParametri (Kalenterimerkinta& aKalenterimerkinta)
{
	aKalenterimerkinta.setAsia("tanaan tapahtuu vaikka mita!");
	aKalenterimerkinta.tulostaKalenterimerkinta();
}

void doSomethingViittausParametri(const Kalenterimerkinta& aKalenterimerkinta)
{
	// T‰m‰ funktio ei voi muuttaa tuodun olion sis‰ist‰ tilaa mitenk‰‰n, voi vain tulostaa jne
	// Funktio voi kutsua VAIN sellaisia metodeja, joilla ei voi muuttaa arvoja.
	// 
	// aKalenterimerkinta.setAsia("tanaan tapahtuu vaikka mita!");		<--- EI onnistu
	aKalenterimerkinta.tulostaKalenterimerkinta();						// <--- onnistuu 
}
int main() {
	
	/*
	
	Kalenterimerkinta merkinta;
	merkinta.kysyTiedot();
	merkinta.tulostaKalenterimerkinta();

	// tehdaan kopio merkinta - > nyt - olioon, jossa asetetaan uusi p‰ivays ////
	/////////////////////////////////////////////////////////////////////////////
	Kalenterimerkinta nyt(merkinta);
	nyt.tulostaKalenterimerkinta();
	
	// vied‰‰n merkinta-olio aliohjelmiin
	// aliohjelma kopioi koko olion aliohjelmaan, tekee sille jotain, tuhoaa sen. P‰‰ohjelmassa
	// pysyyy alkuper‰inen olio muuttumattomana (kuluttaa muistia)
	doSomethingArvoparametri(merkinta);
	merkinta.tulostaKalenterimerkinta();

	// Kyseinen funktio muuttaa myˆs p‰‰ohjelmasta viedyn olion arvoja, jotka tulostuvat
	// p‰‰ohjelmassa
	doSomethingViittausParametri(merkinta);
	merkinta.tulostaKalenterimerkinta();

	*/
		/////////////////////////////////////////////////////////////////////////
		//		Luodaan henkilo - vektori
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
		// Luodaan uusi kaytt‰j‰ 
		if (valikko == 1) {
			tyyppi.kysyTiedot();
			lista.push_back(new henkilo(tyyppi));
		}
		// tulostetaan vektorissa olemassa olevat k‰ytt‰j‰t 
		else if (valikko == 2) {
			for (henkilo* h : lista) {
				h->tulostaHenkilonTiedot();
			}
		}
		// tyhjennet‰‰n vektori sek‰ tyhjennet‰‰n muistiosoitteet
		else if (valikko == 3) {
			lista.clear();
			for (henkilo* h : lista) {
				delete h;
			}
		}
		// tuhotaan haluttu k‰ytt‰j‰ jos lˆytyy, sek‰ sen pointteri
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

	std::cout << std::endl << std::endl;
	std::cout << "Ohjelma paattynyt" << std::endl;



return 0;
}