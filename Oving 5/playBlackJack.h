#pragma once
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"

class Blackjack	{						    //implementerer blackjack-reglene, og regner ut om spiller har vunnet
private:
	CardDeck Kortstokk;					   //kortstokken, arver egenskapene til CardDeck
	int spiller{ 0 };					   //lagrer verdien til spiller
	int dealer{ 0 };					  //lagrer verdien til spiller

public:
	Blackjack();						//Konstruktøren				  
	void playBlackjack();

};

/*
Konstruktøren 
- er en "spesiell medlemsfunksjon" av en klasse som utføres
	når vi lager et objekt av klassen.

- har alltid samme navn som klassen, og har ingen returtype(ikke engang void)
- kan brukes til å sette startverdier til noen medlemsvariabler med
medlemsinitialiseringsliste
*/
