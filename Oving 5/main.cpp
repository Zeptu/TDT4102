#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "playBlackJack.h"
#include <map>


int main(){
//Pre - Card klassen
//	Suits s = Suits::hearts;
//	Rank r = Rank::five;
//	CardStruct c(s,r);
//	CardStruct c2; //default vis
//	
//	cout << suitToString(Suits::spades) << endl;
//
//	cout << rankToString(Rank::two) << endl;
//
//	cout << toString(c) << endl;
//	
//	cout << toStringShort(c) << endl;
//
	setlocale(LC_ALL, "Norwegian");
	srand(time(NULL));
	
	Card kort(Suits::clubs, Rank::king);
	cout << kort.toString() << endl;
	cout << kort.toStringShort() << endl;

	Blackjack blaJ{};		//Oppretter et objekt av klassen blackjack. Kaller objektet blaJ
	blaJ.playBlackjack();	//Kaller på objektet med funksjonen playBlackjack()

	return 0;
}
