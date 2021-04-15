#include "henkilo.h"
#include "paivays.h"
#include "noppa.h"
#include "Osoite.h"
#include "Kalenterimerkinta.h"
#include <vector>
#include "Opettaja.h"
#include "Opiskelija.h"

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
	
	////////////////////////
	// Teht�v�t 1-3 ///////
	/////////////////////// 
	// luodaan Opettaja-olio
	Opettaja ope;
	ope.setKoulutusala("Tietotekniikka");
	ope.lisaaKurssi();
	ope.lisaaKurssi();
	ope.tulostaOpettajanTiedot();
	//poistetaan kurssi, tutkitaan samalla onko sy�tetty� kurssia olemassa
	ope.poistaKurssi();
	//tulostetaan tiedot poiston j�lkeen
	ope.tulostaOpettajanTiedot();
	
	///////////////////////////////////
	// Testataan opiskelija-luokkaa////

	Opiskelija jantteri;
	jantteri.setKurssi();
	jantteri.setKurssi();
	jantteri.setOpintopisteet();
	jantteri.poistaKurssi();
	jantteri.poistaPisteita();
	jantteri.tulostaOpiskelijanTiedot();

	std::cout << std::endl << std::endl;
	std::cout << "Ohjelma paattynyt" << std::endl;
	

	///////////////////////////////////////////////
	//// Teht�v� 4///////////////////////////////

	Opettaja ope1;
	ope1.setKurssi();
	ope1.setKoulutusala("Matematiikka");
	Opettaja ope2("Markku", 34, Osoite("Korkokuja 12", "46786", "Mantta"), "Tietotekniikka");
	Opettaja ope3(ope1);
	ope1.tulostaOpettajanTiedot();
	// tulostaa kopion ope1:st�
	ope3.tulostaOpettajanTiedot();
	ope2.tulostaOpettajanTiedot();

	Opiskelija opiskelija1;
	Opiskelija opiskelija2("Mikko Mallikas", 23, Osoite("Muurikatu 12", "45670", "Lahti"), 12);
	Opiskelija opiskelija3(opiskelija1);
	opiskelija1.tulostaOpiskelijanTiedot();
	opiskelija2.tulostaOpiskelijanTiedot();
	opiskelija3.tulostaOpiskelijanTiedot();

	*/

	////////////////////////////////////////
	///// Teht�v� 5 ///////////////////////
	////////////////////////////////////////

	std::vector<henkilo*> tyypit;

	tyypit.push_back(new (Opiskelija));
	tyypit.push_back(new(Opettaja));
	tyypit.push_back(new(henkilo));


	// kysyy kaksi kertaa ylimaaraista, koska Opettaja ja Opiskelija - oletusrakentajiin on implementoitu kysyTiedot() - metodi.

	for (henkilo* x : tyypit) {
		x->kysyTiedot();
		x->tulostaHenkilonTiedot();
	}



return 0;
}