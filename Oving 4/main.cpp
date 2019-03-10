#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include <ctime>
#include "playMastermind.h"

int main() {
	setlocale(LC_ALL, "Norwegian");
	srand(static_cast<unsigned int>(time(NULL))); //frø - startpunkt for tilfeldighet

	int x = 10;
	while (x != 0) {
		cout << " " << endl;
		cout << "Velg hvilken funksjon du ønsker å kjøre: " << endl;
		cout << "0) Avslutt" << endl;
		cout << "1) CallByValue" << endl;
		cout << "2) CallByReference" << endl;
		cout << "3) swapNumbers" << endl;
		cout << "4) testVectorSorting" << endl;
		cout << "5) testString" << endl;
		cout << "6) testString" << endl;
		cout << "7) playMastermind" << endl;
		
	cin >> x;
	//variabelimplementeringer/deklarasjoner
	vector<int> percentages = {};
	int tall1 = 1;
	int tall2 = 2; 
	string grades;

	switch (x) {

	case 0:
		cout << "Programmet avsluttes. " << endl;
		break;

	case 1:
		testCallByValue();
		break;

	case 2:
		testCallByReference();
		break;

	case 3:
		swapNumbers(tall1, tall2);
		break;

	case 4: 
		testVectorSorting();
		break;

	case 5: 
		grades = randomizeString(8, 'F', 'A'); //kunne også skrevet (8, 1, 6)
		cout << grades << endl;
		break;

	case 6:
		testString();
		break;

	case 7:
		playMastermind();
		break;
		}
	}
		return 0;
}
