#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <vector>


class Paivays
{
public:
	// Constructors:
	Paivays();
	Paivays(const int& aPaiva,const int& aKuukausi,const int& aVuosi);

	// Destructors:
	~Paivays();


	void setPaiva(int& aPaiva);
	void setKuukausi(int& aKuukausi);
	void setVuosi(int& aVuosi);
	int getPaiva() const;
	int getKuukausi() const;
	int getVuosi() const;
	void tulostaPaivaysTanaan() const;
	void tulostaPaivaysHuomenna() const;
	void kysyPaivays();
	void kasvataPaivaysta();
	int tarkistaKuukausi(int& aSyote);

private:
	int paiva;
	int kuukausi;
	int vuosi;
	time_t now = time(0);
	tm* ltm = localtime(&now);
};


