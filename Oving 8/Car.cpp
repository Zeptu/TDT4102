#include "Car.h"

Car::Car(int freeSeats)
	: freeSeats{ freeSeats } {}

bool Car::hasFreeSeats () const {	//HUSK: returtype - klasse - medlem - kropp
	if (freeSeats == 0) 
	{
		return false;
	}
	else 
	{
		return true;
	}
}
void Car::reserveFreeSeat() {	//"reserverer" et ledig sete ved � dekrementere freeSeats - variabelen
	
	--freeSeats;				//Dekrementering = � telle ned verdien til en variabel, ofte med �n
}
