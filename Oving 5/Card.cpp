#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include <map>


string suitToString(const Suits &suit) { //ekstra sikkerhet med const
	return suitStrings.at(suit);	
}

string rankToString(const Rank &rank) {
	return rankStrings.at(rank);	
}


/*Teori: Fordeler med å representere farge på kort som symboler er at det er tryggere og mer lesbart, ettersom
man ikke kan gi ugyldige verdier.*/

string toString(CardStruct c) {
	string str = suitToString(c.s);
	string rnk = rankToString(c.r);
	string cardStruct = rnk + "of" + str;
	return cardStruct;
	cout << rnk << " of " << str << endl;
	//return suitToString(c.s)  + " " + rankToString(card.r); //studass-løsning, samme bare mer komprimert
}

string toStringShort(CardStruct c) {
	int rnk = static_cast<int>(c.r);
	string suit = shortSuit.at(c.s);
	string a{};
	a = suit + " " + to_string(rnk);
	return a;
	cout << a << endl;
}

//Oppgave 3

Suits Card::suit() { //"vi har en funksjon suit som ligger i klassen Card of returnerer verdi av typen Suits"
	return s;
}

Rank Card::rank() {
	return r;
}

Card::Card() {
	valid = false;
}

Card::Card(Suits suit, Rank rank) {
	s = suit;
	r = rank;
	valid = true;
}

bool Card::isValid() {
	return valid;
}

string Card::toString() {
	if (isValid()) {
		return rankToString(r) + " of " + suitToString(s);
}
	else {
		return "Ugyldig kort";
	}
}

string Card::toStringShort() {
	if (isValid()) {
		return shortSuit.at(s) + " " + to_string(static_cast<int>(r));
	}
	else {
		return "Ugyldig kort";
		
	}
}

