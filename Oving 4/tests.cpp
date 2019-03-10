#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"
#include "playMastermind.h"

void testCallByValue() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	cout << "v0: " << v0 << endl;
	cout << "Increment: " << increment << endl;
	cout << "Iterations: " << iterations << endl;
	cout << "Result: " << result << endl;
}


void testCallByReference() {
	int startValue = 5;
	int increment = 2;
	int numTimes = 10;
	int result = incrementByValueNumTimesRef(startValue, increment, numTimes);
	cout << "v0: " << startValue << endl;
	cout << "Increment: " << increment << endl;
	cout << "Iterations: " << numTimes << endl;
	cout << "Result: " << result << endl;
}

void testVectorSorting() {
	vector<int> percentages; 
	//av variabel som heter percentages som er av TYPEN vecot<int> (en vektor som tar inn heltall)
	randomizeVector(percentages, 10);
	swapNumbers(percentages[0], percentages[1]);
	for (auto i : percentages) { //auto
		cout << i << endl;
	}
	cout << endl;
}

void testString() {
	string grades;
	grades = randomizeString(8, 'F', 'A'); //kunne også skrevet (8, 6, 1)
	cout << grades << endl;
	
	vector<int> gradeCount; //romme antall forekomster av hver karakter (A - F)
	double gjennomsnitt;
	for (char i = 0; i < 6; ++i) {
		gradeCount.push_back(countChar(grades, 'A' + i)); //bruker countChar til å fylle gradeCount med antall forekomster av hver karakter
	}
	gjennomsnitt = (5 * gradeCount[0] + 4 * gradeCount[1] + 3 * gradeCount[2] + 2 * gradeCount[3] + gradeCount[4] + 0 * gradeCount[5]) / 6;
	for (auto i : gradeCount) {  //for element i vektor
		cout << i << " ";		//print element
	}
	cout << endl;
	cout << "Gjennomsnittskarakteren ble: " << gjennomsnitt << endl;
}
//5*gradeCount[0]
//snitt = sum/antall
