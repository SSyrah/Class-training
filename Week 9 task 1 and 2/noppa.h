#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>

using std::cout; using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

const int MAX_NOPPIEN_LUKU = 5;

class noppa
{
public:
	noppa();
	noppa(int noppaLkm);

	void setNoppienLkm();
	int getNoppienLkm() const;
	
	void heitaNoppaa();
	int getViimeisinLukema() const;
	void kerroViimeisenHeitonLukema();


private:
	
	int noppaLkm;
	int noppa1;
	int arpakuutio[MAX_NOPPIEN_LUKU];
	time_t now = time(0);
	tm* ltm = localtime(&now);
};

