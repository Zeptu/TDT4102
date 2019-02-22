#include "std_lib_facilities.h"
#include "Oppgave_4.h"

//LESING AV STRUKTURERT FIL 

istream& operator>>(istream& is, Temps& t) { //istream kan v�re cin eller fil eller noe annet //f�r en input stream med to tall
	double minVal;							 //lager en double variabel for minsteVerdi
	double maxVal;							 //lager en double variabel for st�rsteVerdi

	if (!is) {								 //dersom den ikke finner istreamen --> ERROR
		error("ERROR");					
	}
	
	is >> maxVal >> minVal;					 //Skriver ut ord-for-ord

	t.min = minVal;							 //Temp t inneholder to verdier; maks og min
	t.max = maxVal;

	return is;
}
/*
Denne funksjonen overlaster >> - operatoren.
Skal hente informasjon fra en istream og skrive den til v�r type Temps.
*/



//Les Temps fra fil. Les alle temperaturene fra filen og lagre dem som temps-objekter i en vector
void readTempsFromFile() {		
	vector<Temps> hector;
	ifstream temp_file{ "temperatures.txt" };
	Temps t;

	if (!temp_file) {
		error( "File not found" );
	}
	while (temp_file >> t) {
		hector.push_back(t);
	}
	for (Temps t : hector) {
		cout << "Max: " << t.max << ", Min: " << t.min << endl;
	}
}
/*
Tar alle temperaturene helt til det ikke er flere temperaturer � finne:
while (temp_file >> t) FORKLARING
Filen (temp_file) blir en input stream.
Input-streamen sendes med ' >> ' til Temps t
t blir da lagd ut av de f�rste temperaturene i streamen
S� blir t pushet_back til vectoren,
siden streamen ikke er tom, s� sender den de neste temperaturene til Temps t.
og s� gj�r den dette p� mytt helt til streamen er tom.
*/