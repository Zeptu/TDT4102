#include "std_lib_facilities.h"
#include "Oppgave_2.h"

//Lese fra tekstfil og lage statistikk
//Telle antall bokstaver i filen
//telle hvor mange ganger hver bokstav forekommer
//konverter alle bokstavene til små med tolowe(char)
//ifs.get(char)

void charStatistics() {
	ifstream inputFile{ "grunnlov.txt" };

	if (!inputFile) {																				//sjekker filen eksisterer
		error("could not open file", "grunnlov.txt");
	}
		
	char character;																					//lager variabel character 
	vector<int> hector(26, 0);																		//vectoren hector tar 26 plasser med startverdi 0
	int counter{ 0 };
	
	while (inputFile >> character) {
		inputFile.get(character);																	//.get() - funksjonen henter bokstav
		int midlvr = static_cast<int> (character - 'a');											//static_caster til int 
		if (tolower(character) && (character - 'a') >= 0 && (character - 'a') <= 26) {
			hector[midlvr] += 1;																	//legger til 1 i vektorplassen til karakteren som itereres over
			++counter;																				//counter teller totalt antall karakterer i filen
		}
	}
	char x = 'a';																					//Printer alle elementene i hector
	for (auto i : hector) {
		cout << x << " : " << i << endl;
		x++;
	}
	cout << "Det totale antallet karakterer i filen er: " << counter << endl;
}