#include "std_lib_facilities.h"
#include "Oppgave_3.h"

ostream& operator<<(ostream& os, const CourseCatalog& c) {									
	for (auto& i : c.courseMap) {
		os << i.first << i.second << endl;
	}
	return os; 
}
/*
EKSEMPELKODE:
	CourseCatalog cc;
	ofstream os;
	os << cc; // du skriver ut cc ved bruk av ostream
*/

/*
FORKLARING: operator OPERATOR(eks; '<<' )
(Parametere: 1) Venstre side av operatoren, velger hva som kan skrives inn
 Parameter: 2) Høyre side av operatoren, her spesifiserer du f.eks hva som kan skrives ut.
operator <<(ostream&, const CourseCatalog& c

VS: ostream& os --> Du gir en ostream (eks. cout, ostream eller fil) samme funksjonaliteten som cout
HS: const CourseCatalog& c --> Du kan nå skrive ut dette å samme måte som du kan skrive ut en int, string, etc.)

ostream& --> Operatorene returnerer en ostream referanse
*/

void CourseCatalog::addCourse(string courseCode, string courseName) {		//legger til både nøkler og verdier i map
	//courseMap.insert({courseCode, courseName});		//insert	//bruker map_navn.insert - syntaksen (skjønte ikke helt den andre metoden)
	courseMap[courseCode] = courseName;			//[]	
	/*for (const auto& i : courseMap) {					//to cout or not to cout, that! is the question (tror det er lurere å coute i main egt)
	cout << i.first << ": " << i.second << endl;*/
}
//[] tilordner CourseCode en ny verdi, mens insert ikke endrer hvis det allerede eksisterer


void CourseCatalog::removeCourse(string courseCode) {				//removeCourses fjerner emner fra map
	courseMap.erase(courseCode);
}

string CourseCatalog::getCourse(string courseCode) {				//getCourses finner emnenavnet til kurs ved gitt emnekode
	string getName = courseMap[courseCode];					//map_navn[nøkkel] - syntaks henter ut verdien som tilsvarer gitt nøkkel
	return getName;
}

void CourseCatalog::addCourses() {						//medlemsfunksjonen addCourses lar bruker lage en emnekatalog og lagrer i et Map med emnekode som nøkkel
	int numCourses{ 0 };
	string courseCodee{ "" };
	string courseNamee{ "" };

	cout << "Hvor mange emner ønsker du å legge til?" << endl;		//spør bruker om antall emner
	cin >> numCourses;

	for (int i = 0; i < numCourses; ++i) {					//for-løkken som ber om emner, iterasjoner spesifisert av bruker
		cout << "Emnets emnekode: " << endl; cin >> courseCodee;
		cout << "Emnenavn: " << endl; cin >> courseNamee;
		addCourse(courseCodee, courseNamee);
										//bruker addCourse-funksjonen med brukers input som parametre
		string svar;
		

	}
	cout << " Course Catalog: " << endl;				//skriver ut en oversikt over emnene(emnekatalog) på formen "emnekode : emnenavn"
	for (const auto& i : courseMap) {
		cout << i.first << ": " << i.second << endl;
	}
}

void CourseCatalog::writeCourseCatalogToTxtFile() {
	string nameTxtFile{ "" };
	/*cout << "Du ønsker nok å lagre emnekatalogen din i en fil. Navngi filen du ønsker å lagre emnekatalogen i: " << endl; 
	cin >> nameTxtFile;						//lar bruker navngi filen emnekatalogen skal lagres i 
	string fil_navn = nameTxtFile + ".txt";*/
	string navn = "fil_navn.txt";
	ofstream Offs{ navn };						//oppretter en output-stream, og kaller den Offs
	if (!Offs) {
		error(" File not found. ");
	}
	for (const auto& j : courseMap) {				//bruker auto til å itererer gjennom map
		Offs << j.first + " : " + j.second + '\n';		//Ved bruk av Offstreamen min Offs
	}
}

void CourseCatalog::readFromTxtFile(string fil_navn) {
	ifstream Iffs{ fil_navn }; 			//ifstream kan tenkes på som "cin for fil"
	string streng;
	if (!Iffs) {
		error("File not found. ");
	}
	cout << "Lese fra fil: " << endl;
	while (getline(Iffs, streng)) {
		cout << streng << '\n';
	}
}

//getline bruker når du tar input strenger med mellomrom (kan f.eks ikke skille med mellomrom med cin)
//syntaks: getline(cin, string_variable, "evt. valgfritt linjeskifte, eks ":" ")
