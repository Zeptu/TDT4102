#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"
#include "playMastermind.h"
#include <ctime>

//Lag spillet Mastermind
//Lafe tilfeldig kode på 4 bokstaver
//bruker skal gjette bokstaver og rekkefølgen deres
//Etter hver gjetning skal programmet fortelle bruker antall bokstaver de gjetta riktig og hvor mange som ble riktig plassert
//gjenbruk kode!
int checkCharactersAndPosition(string streng1, string streng2);
int checkCharacters(string streng1, string streng2);

void playMastermind() {
	constexpr int size = 4; //antall tegn i koden, 4
	constexpr int letters = 6; //antall ulike bokstaver, 6
	string code = randomizeString(size, 'A' + (letters - 1),  'A');	//koden spilleren skal gjette (FASIT)
	string guess = "";	//bokstaven spilleren gjetter(GUESS)
	int onskedeforsok = 0;
	cout << "Hvor mange forsøk ønsker du å ha?" << endl;
	cin >> onskedeforsok;
	cout << "Dette er spillet Mastermind! Du har " << onskedeforsok << " forsøk. " << endl;
	int forsok = 1;
	int check = 0;
	cout << "Det riktige ordet var: " << code << endl;
	while ((forsok <= onskedeforsok) && (check < size)) {
		guess = readInputToString(size, 'A' + (letters - 1), 'A');
		check = checkCharactersAndPosition(code, guess);
		cout << "Du gjettet " << check << " riktige." << endl;
		cout << "Antall bokstaver på rett plass var " << check << endl;
		cout << endl;
		forsok = forsok + 1;
		if (forsok < onskedeforsok) {
			cout << "Du har dessverre brukt opp dine forsøk. Du tapte." << endl;
			break;
		}
	}
	if (check == size) {
	cout << "Bra jobba, du klarte det!" << endl;
	
	}
	else {
		cout << "Du klarte det ikke, prøv igjen." << endl;
	}
}
//Vi bruker constexpr fordi de initieres umiddelbart? usikker 
//hensiktsmessig å bruke const over constexpr når ...


int checkCharactersAndPosition(string streng1, string streng2) {
	int str = -1;
	int correctGuess = 0;
	int char1 = -2;
	int char2 = -2;
	str = static_cast<int>(streng1.size());
	for (int i = 0; i < str; ++i) {
		char1 = static_cast<int>(streng1[i]);
		char2 = static_cast<int>(streng2[i]);
		if (char1 == char2) {
			correctGuess += 1;
		}
		else {
			continue;
		}
	}
	return correctGuess; //returnere antall riktige bokstaver spilleren gjettet (uavhengig av posisjon)
}

int checkCharacters(string streng1, string streng2) {
	int correctGuess = 0;
	int str = static_cast<int>(streng1.size());
	for (int i = 0; i < str; i++) {
		for (int j = 0; j < str; ++j) {
			if (streng1[i] == streng2[j]) {
				correctGuess += 1;
			}
		}
	}
	return correctGuess; //returnere antall rikgitge bokstaver spiller har gjettet(uavhengig av posisjon)
}

/*CONST vs. CONSTEXPR
CONST variabel 
- for variabler så kompilatorfeil oppstår dersom kode forsøker å endre verdien
- initialisering kan utsettes til kjøretid(når programmet kjører)
CONSTEXPR variabel - initialisering må skje ved kompileringstid()
- for variabler, funksjoner og klasse-kontruktører så kompilatorfeil oppstår dersom kode forsøer å endre verdien
- verdien(returverdien er konstant og (hvis mulig) vil kjøre ved kompileringstid
compile time error - problem som forhindrer programmet fra å kompilere
run time error - 
*/
