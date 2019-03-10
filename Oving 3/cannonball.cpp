#include "cannonball.h"
#include "utilities.h"
#include "std_lib_facilities.h"
#define _USE_MATH_DEFINES
#include <math.h>

//for å få hjelp av kompilatoren til å oppdage skrive/småfeil er det god tommelfingerregel å inkludere headerfilen(e) som inneholder deklarasjoner for de funksjonene som skal implementeres

//2) IMPLEMENTERE funksjoner

//a) Akselerasjon i y-retning.

double acclY() {
	double AkselerasjonY = -9.81;
	return AkselerasjonY;
}

//b) Fart i y-retning.

double velY(double initVelocityY, double Tid) {
	double velocityY = initVelocityY +  acclY() * Tid;
	return velocityY;
}

//c) 
double posX(double initPosition, double initVelocityX, double time) {
	double AkselerasjonX = 0;
	double PosisjonX = initPosition + initVelocityX * time + ((AkselerasjonX * pow(time, 2)) / 2);
	return PosisjonX;
}
double posY(double initPosition, double initVelocityY, double time) {
	double AkselerasjonY = -9.81;
	double PosisjonY = initPosition + initVelocityY * time + ((AkselerasjonY * pow(time, 2)) / 2);
	return PosisjonY;
}

//d)Utskrift av tid.

void printTime(double sekunder) {
		int timer = static_cast<int> (sekunder) / 3600; //heltallstimer
		int minutter = (sekunder - (3600 * timer)) / 60;	//minutter
		int i = sekunder - (3600 * timer) - (minutter * 60); //sekunder
		cout << sekunder << " sekunder blir " << timer << " time(r), " << minutter << " minutter og " << i << " sekunder. " << endl;

		//kan egentlig ikke konvertere fra double til int, men den lar meg kompilere?
}


//e)
double flightTime(double initVelocityY) {
	double Flyvetid = ((-2 * initVelocityY) / acclY());
	return Flyvetid;
}

//4) Gjenbruk av funksjoner. 

//Referanser benyttes for å returnere mer enn én verdi fra en gitt funksjon. 
//a) 

//ber bruker om vinkel i grader og en fart
//theta og absVelocity er referanser til objektene funksjonen kalles med

void getUserInput(double& theta, double& absVelocity) {
	cout << "Gi en vinkel i grader: " << endl;
	cin >> theta;
	cout << "Gi en fart : " << endl;
	cin >> absVelocity;

}

//Konverterer fra grader til Radianer
double degToRad(double theta){
	double rad = theta * (M_PI / 180);
	return rad;
	cout << "Vinkelen du ga konvertert til radianer blir: " << rad << endl;
}

//Returnerer hhv. farten i x-, og y-retning, gitt en vinkel.
//theta er en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity) {
	double VelocityX = absVelocity * cos(theta);
	return VelocityX;
	cout << " Hastigheten i  x - retning er: " << VelocityX << endl;
}

double getVelocityY(double theta, double absVelocity) {
	double VelocityY = absVelocity * sin(theta);
	return VelocityY;
	cout << " Hastigheten i  y - retning er: " << VelocityY << endl;
}

//dekomponerer farten gitt av absVelocity, i x- og y- komponentene.

void getVelocityVector(double theta, double absVelocity, double& velocityX, double& velocityY) {
	velocityX = getVelocityX(theta, absVelocity);
	velocityY = getVelocityY(theta, absVelocity);
}

//b) Implementer funksjon

double getDistanceTraveled(double velocityX, double velocityY) {
	double time = flightTime(velocityY);
	double time2 =  time * velocityX;
	double posY = 0.0;
	//ganger tiden med hastigheten til x for å finne hvor langt vi har kommet. x = vt
	double horisontalPos = posX(posY, velocityY, time);
	return horisontalPos;
}

//c) Implementere funksjonen targetPractice()

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
	return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
	//cout << "Skuddet ditt landet " << distanceToTarget << " fra det ønskede målet. " << endl;
}

//ta inn avstand distanceToTarget, returnerer avviket i meter mellom verdien distanceToTarget 
//og der kulen lander (avstand fra start i x-retning) når velocityX og velocityY er hhv. 
//startfart i x-og y-retning










