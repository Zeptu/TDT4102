#pragma once
#include "std_lib_facilities.h"
#include "Card.h"

class CardDeck {
private:
	vector<Card> cards;
	int currentCardIndex;
	void swap(int a, int b);
	
public:
	CardDeck();
	void print();
	void printShort();
	void shuffle();
	const Card& drawCard();
	
};

/*
Public vs. private
- Handler om klassenes relasjon til hverandre
- Noe som er privat ei en klasse vil kun kunne endres av den klassen
- Noe som er public i en klasse vil kunne endres av andre klasser
- tror dette er greia, spør studass
*/
