#include "Osoite.h"

// constuctors and destructors 

Osoite::Osoite() : kunta("N/A"), postinumero("N/A"), katuosoite("N/A")
{
    std::cout << "Osoite-luokan parametriton rakentaja aktivoitu" << std::endl;
}

Osoite::Osoite(const std::string& aKatuosoite, const std::string& aKunta, const std::string& aPostinumero)
    : katuosoite(aKatuosoite), postinumero(aPostinumero), kunta(aKunta)
{
    std::cout << "Osoite-luokan parametrinen rakentaja aktivoitu" << std::endl;
}

Osoite::~Osoite()
{
    std::cout << "Osoite-luokan purkaja aktivoitu" << std::endl;
}

std::string Osoite::getKatuosoite() const
{
    return katuosoite;
}

std::string Osoite::getPostinumero() const
{
    return postinumero;
}

std::string Osoite::getKunta() const
{
    return kunta;
}

void Osoite::setKatuosoite(const std::string& aKatuosoite)
{
    katuosoite = aKatuosoite;
}

void Osoite::setPostinumero(const std::string& aPostinumero)
{
    postinumero = aPostinumero;
}

void Osoite::setKunta(const std::string& aKunta)
{
    kunta = aKunta;
}

void Osoite::tulostaTiedot() const
{
    std::cout << "Katuosoite on: " << katuosoite << std::endl;
    std::cout << "Postinumero on: " << postinumero << std::endl;
    std::cout << "Kunta on: " << kunta << std::endl;
}

void Osoite::kysyOsoitetiedot()
{
    std::cin.clear();
    std::cout <<"Kerro osoitteesi: ";
    std::getline(std::cin, katuosoite);
    std::cin.clear();
    std::cout << "Kerro postinumerosi: ";
    std::getline(std::cin, postinumero);
    std::cin.clear();
    std::cout << "Kerro kotikuntasi: ";
    std::getline(std::cin, kunta);
    std::cout << std::endl;
}

