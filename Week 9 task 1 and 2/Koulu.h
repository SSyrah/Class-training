#pragma once
#include "henkilo.h"
#include "Opettaja.h"
#include "Opiskelija.h"
class Koulu :    public henkilo
{
public:
	// rakentajat ja purkajat
	Koulu();
	Koulu(const std::string& akoulunNimi, const Opettaja& aOpettajat, const Opiskelija& aOpiskelijat);
	~Koulu();
	// setterit ja getterit

	void setOpiskelija();
	void setOpettaja();

	void tulostaOpiskelija() const;
	void tulostaOpettaja() const;
	void tulostaKoulunTiedot() const;

	std::vector<Opiskelija*> getOpiskelijat() const;
	std::vector<Opettaja*> getOpettajat() const;
	

private:
	std::string koulunNimi;
	std::vector<Opettaja*> Opettajat;
	std::vector<Opiskelija*> Opiskelijat;
};

