#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "playMastermind.h"


/*a)

Verdien skrevet ut for v0 når programmet har kjørt ferdig er 5. 
Verdien for resultatet blir 25. 

*/

//pass-by-red lager ikke kopi - nyttig!

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
	return startValue;
}

int incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
	return startValue;
}

void swapNumbers(int &a, int &b) {
	cout << "Før bytte: " << "a = " << a << ", b = " << b << endl;
	int midlertidigvariabel = a;
	a = b;
	b = midlertidigvariabel;
	cout << "Etter bytte: " << "a = " << a <<  ", b = " << b << endl;

}

void randomizeVector(vector <int>& v, int n) {
	for (int i = 0; i < n; ++i) {
		int random = rand() % (100 - (0 + 1) + 0);
		v.push_back(random);
		
	}
}

//insertion sort - sorteringsalgoritme
void sortVector(vector<int>& A) {
	int i = 1;
	while (i < A.size()) {
		int j = i;
		while ((j > 0) && (A[j - 1] > A[j])) {
			swapNumbers(A[j], A[j - 1]);
			j = j - 1;
		}
		i = i + 1;
	}	
}

double medianOfVector(const vector<int> vektor) {
	
	if (vektor.size() % 2 != 0) {	//oddetall
		double median = vektor[vektor.size() / 2];
		return median;
		cout << median << endl;
		}
	else { //partall
		int median = (vektor[vektor.size() / 2 - 1] + vektor[vektor.size() / 2]) / 2;
		return median;
		cout << median << endl;
		}
}

string randomizeString(int lengdeCh, char upLimCh, char lowLimCh) { 
	string randCh;
	for (int i = 0; i < lengdeCh; ++i) {
		char randombok = rand() % (upLimCh+1 - lowLimCh) + lowLimCh;		//random inneholder et tilfeldig heltall ;
		randCh = randCh + randombok;											//å kjøre srand med time(nullptr) gir rand en unik tallrekke hver gang programmet kjøres, så lenge man gjør det med et sekunds mellomrom
																			//fordi srand forventer en unsigned int må vi utføre en eksplisitt type-konvertering static_cast på verdien time returnerer
	}
	return randCh;
}


string readInputToString(int n, char upLimCh, char lowLimCh) {
	int i = 0;
	string inputString = { "" };
	while (i < n) {
		cout << "Gi en karakter i form av en bokstav eller et tall. " << endl; 
		char c;
		cin >> c;
		c = toupper(c);
		if ((isalpha(c)) && ((lowLimCh <= c && c <= upLimCh))) {//OBS
			cout << "Du skrev inn en gyldig karakter." << endl;
			inputString.push_back(c);
			++i;
		}
		else if ((isdigit(c) && (lowLimCh <= c  && c <= upLimCh))) { //OBS bruk 'c < && c <' heller enn '< c <' 
			cout << "Du skrev inn en gyldig karakter." << endl;
			inputString.push_back(c);
			++i;
		}
		else {
			cout << "Karakteren du ga var ugyldig, gi en ny. " << endl;
		}
	}
	return inputString;
}

//nyttige funksjoner: toupper(c), tolower(c), isdigit(c)
//skal returnere en streng av gitt lengde n
//øvre og nedre grense for tillatte tegn
//returnert streng fylles vha. cin
//sjekke om input består av alfanumeriske tegn
//sjekke om input er innenfor øvre og nedre grense (for både store og små bokstaver godkjennes)
//alfanumerisk = både alfabetiske og numeriske tegn(dvs Aa - Zz og 0 - 9)
//ikke printe før gyldig streng eksisterer!

int countChar(string a, char b) { //tar inn en int og en char
	int antall = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == b) {
			antall += 1;
		}
	}
	return antall; 
	cout << "Karakteren" << b << " forekom" << antall << " antall ganger i strengen." << endl;
}
