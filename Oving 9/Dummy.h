#pragma once
#include <utility>
#include <iostream>

using namespace std;

class Dummy {
public:
	//Kopinstrukt�r
	Dummy(const Dummy& dum);

	//Deklarerer peker num
	int *num;

	//Konstrukt�r - Allokerer dynamisk minne for num-pekeren
	Dummy() 
	{
		num = new int{ 0 };
	}

	//Destrukt�ren - Frigj�r minnet tidligere allokert av num, viktig � frigj�re minne for � unng� feil
	~Dummy() 
	{
		delete num;
	}

	//Overskriver tilordningsoperatoren slik at den kan ta et Dummy - element
	Dummy &operator=(Dummy rhs);
};

//Lager en funksjon dummyTest for � teste at overskrivningen av tilordningsoperatoren og 
//konstruksjon av kopikonstrukt�ren fungerte
void dummyTest();

