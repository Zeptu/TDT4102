#pragma once
#include "std_lib_facilities.h"


//Oppretter scoped-enum

enum class Suits{ clubs, diamonds, hearts, spades };							//Lager enum-class-typen Suits
enum class Rank{ two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen , king , ace };	//Lager enum-class-typen Rank

const map<Suits, string> suitStrings {	//map_1
	{Suits::clubs, "Clubs"},
	{Suits::diamonds, "Diamonds"},
	{Suits::hearts, "Hearts"},
	{Suits::spades, "Spades"} };

const map<Rank, string> rankStrings {  //map_2
	{Rank::two, "Two"},
	{Rank::three, "Three"},
	{Rank::four, "Four"},
	{Rank::five, "Five"},
	{Rank::six, "Six"},
	{Rank::seven, "Seven"},	
	{Rank::eight, "Eight"},
	{Rank::nine, "Nine"},
	{Rank::ten, "Ten"},
	{Rank::jack, "Jack"},
	{Rank::queen, "Queen"},
	{Rank::king, "King"},
	{Rank::ace, "Ace"} };

const map<Suits, string> shortSuit { //map_3
	{Suits::clubs, "C"},
	{Suits::diamonds, "D"},
	{Suits::hearts, "H"},
	{Suits::spades, "S"} };

/*switch () {
	case Rank::two:
		cout << "Two" << endl;
		break;
	case Rank::three:
		cout << "Three" << endl;
		break;
	case Rank::four:
		cout << "Four" << endl;
		break;
	case Rank::five:
		cout << "Five" << endl;
		break;
	case Rank::six:
		cout << "Six" << endl;
		break;
	case Rank::seven:
		cout << "Seven" << endl;
		break;
	case Rank::eight:
		cout << "Eight" << endl;
		break;
	case Rank::nine:
		cout << "Nine" << endl;
		break;
	case Rank::ten:
		cout << "Ten" << endl;
		break;
	case Rank::jack:
		cout << "Jack" << endl;
		break;
	case Rank::queen:
		cout << "Queen" << endl;
		break;
	case Rank::king:
		cout << "King" << endl;
		break;
	case Rank::ace:
		cout << "Ace" << endl;
		break;
	}*///Switch

string suitToString(const Suits &suit);
string rankToString(const Rank &rank);

struct CardStruct {
	CardStruct() = default;					//Default konstruktør
	CardStruct(Suits s, Rank r) : s{ s }, r{ r } {};  	//Delegerende konstruktør 
	Suits s;						//Variabel av typen Suits
	Rank r;							//Variabel av typen Rank
};
/*
En struct er som en klasse, bare at alt er public med mindre noe annet blir spesifisert, og vi bruker den som regel bare til å lagre data (eks variabler). 
I klasser har vi konstruktører. Det er konstruktørene som "aktiverer" medlemsfunskjonene og medlemsvariablene i klassen. Konstruktører brukes til å initialisere objekter fra sin klasse.
Konstruktører finner vi også i Structs (husk: Klasse == Struct (nesten)). I Structen CardStruct har vi to konstruktører. En default konstruktør som kalles dersom 
en medlemsfunksjon ikke blir gitt parametere, og en annen konstruktør som kalles dersom en funksjon blir gitt parametere. (tror jeg)
DELEGERENDE KONSTRUKTØRER lar oss velge hvilken konstruktør vi ønsker å bruke, selv om vi har flere alternativer. (tror jeg)
*/

string toString(CardStruct c);

string toStringShort(CardStruct c);

class Card {						//ikke spesifisert gjør det automatisk private(klasse), og public (struct) 
public:								
	Card();
	Card(Suits suit, Rank rank);
	Suits suit();
	Rank rank();
	bool isValid();
	string toString();
	string toStringShort();
	//int rankToInt(CardStruct c);

private:
	Suits s;
	Rank r;
	bool valid;					//sjekker om kortet er gyldig
};

/*Teori: Vi ønsker å representere spillkortet som en klasse framfor en struct fordi vi bruker klasser
når vi ønsker å organisere mer enn bare data, eks funskjoner mm. Invarianten i en klasse er private som default, i motsetning
til i en struct hvor alt er public som default
*/

//medlemsvariabler? medlemsfunksjoner?
//typer = et løfte/kontrakt om hvordan noe ser ut for c++ (hva du tar inn altså)
