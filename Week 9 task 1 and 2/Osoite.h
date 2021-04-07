#pragma once
#include <iostream>
#include <string>
#include <vector>

class Osoite
{
public:
	Osoite();
	Osoite(const std::string& aKatuosoite, const std::string& aKunta, const std::string& aPostinumero);
	~Osoite();
	std::string getKatuosoite() const;
	std::string getPostinumero() const;
	std::string getKunta() const;
	void setKatuosoite(const std::string& aKatuosoite);
	void setPostinumero(const std::string& aPostinumero);
	void setKunta(const std::string& aKunta);
	void tulostaTiedot() const;
	void kysyOsoitetiedot();

private:
	std::string katuosoite;
	std::string kunta;
	std::string postinumero;
};

