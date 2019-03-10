#include "std_lib_facilities.h"
#include "Oppgave_1.h"


//ostream = output stream, eks: cout (skriver ut informasjon)
//ifstream = input stream, eks: cin (tar inn informasjon)


string writeToFile() {						//Funksjonen skriver til fil
	string input{ "" };
	ofstream ofs{ "mintekstfil.txt" };
	
	while (true) {
		cout << "Skriv inn et ord" << '\n';
		cin >> input;
		if (input == "quit") {    
			break;
		}
		if (!ofs) {
			error("can not open file");
		}
		ofs << input << '\n';
	}
	return input;
}

void readFromFile() {						//Funksjonen leser fra fil 
	string linje{ "" };
	ifstream ifs{ "mintekstfil2.txt" }; 			//Navngi fil den skal lese fra 
	ofstream ofs{ "nymintekstfil2.txt" };			//Navngi den nye filen den skal lese til
	
	if (!ifs) {
		error("can not open file");
	}
	while (getline(ifs, linje)) {
		cout << linje << '\n';

	if (!ofs) {
		error("can not open file");
	}
	ofs << linje << '\n';
	
	}	
}
