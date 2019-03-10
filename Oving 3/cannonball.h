#pragma once
#include "std_lib_facilities.h"
//pragma once er en header guide, den  hindrer oss fra å inkludere en header-fil mer enn en gang
//"only include this file once"
//Oppgave 1) Funksjondeklarasjoner (10%)
//"headerfil : Hey, this function exists"
//Header-filer inneholder bare deklarasjoner, ikke definisjoner/implementasjoner
//Husk: kan kun definere en funksjon én gang
//bruker kun .h til å deklarere funskjoner, ikke variabler (i dette emnet)

//1) FunksjonsDEKLARASJONER

	//a) Akselerasjon i y-retning.

double acclY();

//b) Farten i y-retning.

double velY(double initVelocity, double time);

	//c) Posisjon i hhv. x- og y-retning.

double posX(double initPosition, double initVelocity, double time);

double posY(double initPosition, double initVelocity, double time);

	//d)Utskrift av tid.

void printTime(double sekunder);

	//e) Flyvetid

double flightTime(double initVelocityY);

void testDeviation(double compareOperand, double toOperand, double maxError, string name);

//4a)
double degToRad(double theta);

void getUserInput(double& theta, double& absVelocity);

double getVelocityX(double theta, double absVelocity);

double getVelocityY(double theta, double absVelocity);

void getVelocityVector(double theta, double absVelocity, double& velocityX, double& velocityY);

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double velocityX, double velocityY);


//pss: parameternavn er ikke egetlig nødvendig i headerfiler, bare typen er viktig
//men når du har en referanse må du ha med, for da er typen referansen
