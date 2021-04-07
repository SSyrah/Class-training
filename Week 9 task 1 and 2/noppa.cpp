#include "noppa.h"


noppa::noppa() : noppa1(0), noppaLkm(1), arpakuutio()
{
	std::cout << "oletus-rakentaja aktivoitu:" << noppa1 << std::endl;
}

noppa::noppa(int noppaLkm) : noppa1(0), noppaLkm(noppaLkm), arpakuutio()
{	
	std::cout << "Parametrinen rakentaja aktivoitu" << std::endl;
	if (noppaLkm <= MAX_NOPPIEN_LUKU) {
		noppaLkm = noppaLkm;
	}
	else {
		std::cout << "Liian suuri tai pieni noppien lukumaaara." << std::endl;
		setNoppienLkm();
	}
	
}

void noppa::setNoppienLkm()
{
	bool test = false;
	do {
		test = false;
		std::cout << "Kuinka montaa noppaa haluat kayttaa (1-5)?: ";
		std::cin >> noppaLkm;
		if (std::cin.fail() || noppaLkm < 1 || noppaLkm > 5) {
			test = true;
			std::cout << "syotit liian suuren/pienen arvon tai kirjaimia, syota uudelleen." << std::endl;
			std::cin.clear();
			std::cin.ignore(20, '\n');
		}
		else {}

	} while (test);
}


int noppa::getNoppienLkm() const
{
	return noppaLkm;
}

void noppa::heitaNoppaa()
{
	//	pieni testikokeilun tynkää saada rand-funkiosta enemmän satunnainen. kokeilin alustaa noppa1 systeemin kellonajan mikrosekunneista ennen rand-funktiota. 
	//  noppa1 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	//  std::cout << "Systeemin kellonajan mikrosekunnit ajon aikana:\t" << noppa1 << std::endl;
	srand(time(nullptr));
	noppa1 = rand() % 6 + 1;

	for (int i = 0; i < noppaLkm; i++) {
		arpakuutio[i] = rand() % 6 + 1;
	}

}

int noppa::getViimeisinLukema() const
{
	return noppa1;
}

void noppa::kerroViimeisenHeitonLukema()
{
	// std::cout << "Viimeisimmän nopan heiton lukema oli:\t" << noppa1 << std::endl;
	std::cout << "Noppien lukemat olivat seuraavat:" << std::endl;
	for (int i = 0; i < noppaLkm; i++) {
		std::cout << "Noppa " << i + 1 << " : " << arpakuutio[i] << std::endl;
	}
	std::cout << "Viimeisen heiton yhteislukema oli: ";
	for (int i = 0; i < (noppaLkm - 1); i++) {
		arpakuutio[0] += arpakuutio[i + 1];
	}
	std::cout << arpakuutio[0] << ". Heitossa kaytettiin " << noppaLkm << " noppaa." << std::endl<<std::endl;
}

