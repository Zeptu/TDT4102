#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
	
	double differansen = (compareOperand - toOperand);
	double abs_differansen = abs(differansen);
	cout << abs_differansen << endl;
}

int main(){


	setlocale(LC_ALL, "Norwegian");
	srand(static_cast<unsigned int>(time(nullptr)));
	
	//frø(seed) er startpunkt for tilfeldighet
	//matematikk er deterministisk, dette gjør tilfeldighet vanskelig
	//srand brukes til å initiere hvilket frø som skal brukes
	//initialiserer random frø

	double distanceToTarget = 0;
	double target = 0;
	acclY();
	cout << endl;
	cout << "Farten i Y-retning er: " << velY(0.475, 2.5) << endl;
	cout << endl;
	cout << "Posisjonen i X-retning er: " << posX(0.0, 50.0, 5.0) << endl;
	cout << endl;
	cout << "Posisjonen i Y-retning er: " << posY(0.0, 25.0, 2.5) << endl;
	cout << endl;
	printTime(3661); //er void, returnerer ingenting //kan ikke coutes //returnerer nada
	cout << endl;
	cout << "Flyvetiden er: " << flightTime(4.0) << " sekunder." << endl;
	cout << "" << endl;
	cout << "Feilverdien er: " << endl;
	testDeviation(posX(0.0, 50.0, 5.0), 250.001, 0.001, "posX(0.0, 50.0, 5.0)");
	cout << endl;
	double theta;
	double absVelocity;
	double velocityX;
	double velocityY;
	getUserInput(theta, absVelocity);
	theta = degToRad(theta);
	getVelocityVector(theta, absVelocity, velocityX, velocityY);
	cout << "Hastigheten i horisontal(x) - retning er: " << velocityX << ", hastigheten i vertikal(y) - retning er:  " << velocityY << ". Kulen ble kastet " << getDistanceTraveled(velocityX, velocityY) << " meter." << endl;
	cout << endl;
	cout << "Skuddet ditt landet " << abs(targetPractice(50, velocityX, velocityY)) << " meter fra det ønskede målet. " << endl;
	cout << endl;
	cout << "Tilfeldig tall: " << randomWithLimits(100, 10000) << endl;
	cout << "Dette er et spill hvor du skal gjette posisjonen til en kanonkule. Du har 10 forsøk. " << endl;
	playTargetPractice();


	return 0;
}
