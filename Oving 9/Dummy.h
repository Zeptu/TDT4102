#pragma once
#include <utility>
#include <iostream>

using namespace std;

class Dummy {
public:
	//Kopinstruktør
	Dummy(const Dummy& dum);

	//Deklarerer peker num
	int *num;

	//Konstruktør - Allokerer dynamisk minne for num-pekeren
	Dummy() 
	{
		num = new int{ 0 };
	}

	//Destruktøren - Frigjør minnet tidligere allokert av num, viktig å frigjøre minne for å unngå feil
	~Dummy() 
	{
		delete num;
	}

	//Overskriver tilordningsoperatoren slik at den kan ta et Dummy - element
	Dummy &operator=(Dummy rhs);
};

//Lager en funksjon dummyTest for å teste at overskrivningen av tilordningsoperatoren og 
//konstruksjon av kopikonstruktøren fungerte
void dummyTest();

