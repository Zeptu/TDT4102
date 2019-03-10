#pragma once
#include "std_lib_facilities.h"

class Car 
{
private:
	int freeSeats;							//hvor mange ledige seter det er i bilen
	
public:
	Car(int freeSeats);
	bool hasFreeSeats() const;				//return true dersom ledige seter
	void reserveFreeSeat();					//"reserverer" et ledig sete ved å dekrementere freeSeats - variabelen
	
};

//Merk: const - deklarasjon kommer ETTER argumentene
