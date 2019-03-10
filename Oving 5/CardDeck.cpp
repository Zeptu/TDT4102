#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"


CardDeck::CardDeck() {		//Lager kortstokken i vektoren cards, pusher inn alle 14 kortene av hver av de 4 mønstrene (som en gangetabell)
	currentCardIndex = 0;
	for (int s = 0; s < 4; ++s) {
		for (int r = 2; r < 15; ++r) {
			cards.push_back(Card((Suits(s)), (Rank(r)))); //bruker push.back til å fylle vektoren
		}
	}
}

void CardDeck::swap(int a, int b) {		//swap bytter plass på to kort, koden lages ved å benytte en midlertidig variabel
	Card midlvr = cards[a];
	cards[a] = cards[b];
	cards[b] = midlvr;
}

void CardDeck::print() {			//"En funskjon fra klassen CardDeck som heter print og har returverdi av typen void"
	for (Card c : cards) {				//"For hvert element (element c fra klassen Card) i cards, print element i toString - fomat"
		cout << c.toString() << endl;
	}
}

void CardDeck::printShort() {			//Printer elementene i toStringShort - format
	for (Card c : cards) {
		cout << c.toStringShort() << endl;
	}
}

void CardDeck::shuffle() {				//shuffle går gjennom alle elementene i  vektoren cards og bruker så swap-funksjonen som vha. rand() tar to tilfeldige elementer fra vektoren og bytter plass på dem
	for (int i = 0; i < cards.size(); ++i) {									//dette gjør den for alle kortene i kortstokken vår (cards)
		swap( (rand() % (cards.size())), (rand() % (cards.size())) );			//rand() % fungerer s.a. resten alltid vil ligge innenfor intervallet av din øvre og nedre grense
	}
}

const Card& CardDeck::drawCard() {					//funksjonen drawCard trekker et kort fra cards
	++currentCardIndex;
	return cards[currentCardIndex - 1];				//henter element fra cards med indeks [cCI - 1]
}													//shuffler bunken, og returnerer bunken uten kortet du har tatt