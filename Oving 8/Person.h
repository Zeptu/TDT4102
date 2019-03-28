#pragma once
#include "std_lib_facilities.h"
#include "Car.h"

class Person 
{
private:
	string name, email;
	Car* car;		//privat medlemsvariabel car som er en peker til Car*

public:
	Person(string name, string email, Car* car = nullptr);	//Setter car sin defaul til nullptr, default-argumentt må være det siste i parameterlista
	string getName() const;
	string getEmail() const;
	void setEmail( string nyemail );
	bool hasAvailableSeats() const;

	friend ostream& operator<<(ostream& os, const Person& person); /*Skal skrive ut innholdet i Person til en ostream
									må deklareres friend for å få tilgang på klassen, operatorer kan ikke være medlemsfunksjoner. Friend-deklarasjon
									gir operatoren tilgang på den delen av klassen som er deklarert private.*/
};
/*
Drøft:
- Operatorer bør deklareres med const-parametere fordi ....

- Vi bør bruke const-parametere når ........

- Vi KAN IKKE bruke const-parametere når ........
*/
