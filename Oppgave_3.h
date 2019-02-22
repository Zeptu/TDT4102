#pragma once
#include "std_lib_facilities.h"


class CourseCatalog {
private:
	map<string, string> courseMap;											//Oppretter map

public:
	CourseCatalog() {}														//Oppretter konstruktør
	friend ostream& operator << (ostream& os, const CourseCatalog& c);		//skriv ut alle emnekoder med tilhørende emnenavn
	void addCourse(string courseName, string courseCode);					//legg til et kurs med emnekode og emnenavn
	void removeCourse(string courseCode);									//fjern et kurs gitt av emnekoden
	string getCourse(string courseCode);									//finn emnenavnet til et kurs med en gitt emnekode
	void addCourses();														//lar bruker legge til emner i map
	void readFromTxtFile(string fil_navn);									//leser fra fil
	void writeCourseCatalogToTxtFile();										//skriver til fil
									
};

/*
Operatorer kan ikke være medlemsfunksjoner (for det meste), derfor har vi dem heller som friend.
Ved å ha dem som friend får de tilgang på de PRIVATE delene av klassen, så i dette tilfellet gir
vi operatoren tilgang på map. 
*/