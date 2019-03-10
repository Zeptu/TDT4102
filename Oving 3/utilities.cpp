#include "std_lib_facilities.h"
#include "ctime"
#include "cstdlib"
#include "utilities.h"
#include "cannonball.h"

//b) 

	int randomWithLimits(int lowLim, int upLim) {
		int tilfeldig_tall = rand() % (upLim - (lowLim + 1) + lowLim);  //tallet du vil gå opp til grense ved å skrive + 1; 
		return tilfeldig_tall;
	}

//d) SPILL

	void playTargetPractice() {
//setter målet til et tilfeldig tall mellom 100 og 1000
		int blinken = randomWithLimits(100, 1000);

//deklarerer variablene som skal tas som parametere i getUserInput
		double theta;
		double initVel;
		double radianer;

		for (int i = 0; i <= 10; ++i) {
			//husk: løkken kjører mens begge betingelsene er oppfylt, 
			//du kan derfor ikke ha i = 10 fordi det ikke er tilfellet, men i <=10 fungerer fint

		//Leser inn vinkel og startfart
			getUserInput(theta, initVel);

		//Konverter vinkel til radianer
			radianer = degToRad(theta);

			
		//Skyte med kanonen mot tilfeldig plassert blink
			double forsok = targetPractice(blinken, getVelocityX(radianer, initVel), getVelocityY(radianer, initVel));
			cout << "Tiden kulen var i luften var "  << flightTime(initVel) << " sekunder." << endl;

			if (forsok < blinken - 5 || forsok > blinken + 5) {
				cout << "Du var " << forsok << " meter unna målet" << endl;

				if (forsok > blinken + 5) {
					cout << "Du kastet for langt, prøv igjen.  " << endl;
				}
				if (forsok < blinken - 5) {
					cout << "Du kastet for kort, prøv igjen. " << endl;
				}
			}
			else {
					cout << "Du var " << forsok << " meter unna målet" << endl;
					cout << "Gratulerer, kastet ditt landet innenfor det ønskede intervallet!" << endl;
					break;
				}
			


		}
	}
	

	


	//referanser - endrer verdien også utenfor funksjonen
	//endrer på den opprinnelige minneplasseringen
	//call-by-rreference - denne variabelen ligger på denne minneplasseringen
	//istedenfor å lage en kopi som ved call-by-value
