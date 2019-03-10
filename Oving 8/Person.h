#pragma once
#include "std_lib_facilities.h"
#include "Car.h"

class Person 
{
private:
	string name, email;
	Car* car;											//privat medlemsvariabel car som er en peker til Car*

public:
	Person(string name, string email, Car* car = nullptr);	//Setter car sin defaul til nullptr, default-argumentt m� v�re det siste i parameterlista
	string getName() const;
	string getEmail() const;
	void setEmail( string nyemail );
	bool hasAvailableSeats() const;

	friend ostream& operator<<(ostream& os, const Person& person);   /*	Skal skrive ut innholdet i Person til en ostream
																		m� deklareres friend for � f� tilgang p� klassen, operatorer kan ikke v�re medlemsfunksjoner. Friend-deklarasjon
																		gir operatoren tilgang p� den delen av klassen som er deklarert private.
																	 */
};
/*
Dr�ft:
- Operatorer b�r deklareres med const-parametere fordi ....

- Vi b�r bruke const-parametere n�r ........

- Vi KAN IKKE bruke const-parametere n�r ........
*/
