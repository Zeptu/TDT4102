#include "std_lib_facilities.h"
//ØVING 2 - KAP 1, 2, 3 & 4//
//1) Funksjoner og Input/Output

//a)

void inputAndPrintInteger() {
	int a = 0; 
	cout <<  "Skriv inn et heltall:" << endl;
	cin >> a;
	cout << "Du skrev:" << " " << a << endl;
}

//b)

int inputInteger() {
	int b = 0;
	cout << "Skriv inn et heltall:" << endl;
	cin >> b;
	return b;
}

//c)

int inputIntegersAndPrintSum() {
	int x = inputInteger();
	int y = inputInteger();
	return x + y;
}

//d) Jeg valgte å benytte inputIntegersAndPrintSum fordi den er mer oversiktlig i mine øyne

//e)
bool isOdd(int a) {
		if (a % 2 != 0) {
			return true;
		}
		else {
			return false;
		}
	}

//f)
void printHumanReadableTime(int sek) {
	int timer = sek / 3600; //heltallstimer
	int min = (sek - (3600*timer))/60;	//minutter
	int i = sek - (3600 * timer) - (min * 60); //sekunder
	cout << sek << " sekunder blir " << timer << " time(r), " << min << " minutter og " << i << " sekunder. " << endl;

}

//2)
//a)
int inputIntegersUsingLoopAndPrintSum() {
	int e;
	int f;
	int sum = 0;
	cout << "Hvor mange tall vil du summere?" << endl;
	cin >> e;
	for (int x = 0; x < e; ++x) {
		cout << "Gi et heltall: " << endl;
		cin >> f;
		sum += f;
		}
	cout << "Summen av tallene er: " << sum << endl;

	return sum;
	}

//b) Kjent antall repetisjoner: for-løkker. Ukjent antall repetisjoner: while-løkker. 

//c)
double inputDouble() {
	double r;
	cout << "Skriv inn et flyttall: " << endl;
	cin >> r;
	return r;
}

//d) 

double nokTilEuro() {
	double valuta = 9.7358;
	cout << "Dette er en valutakonvertør. Her kan du konvertere beløp fra NOK til Euro." << endl;
	double nok = inputDouble();
	while (nok < 0) {
		cout << "Gi et nytt tall: " << endl;
		nok = inputDouble();
	}
	double euro = (nok * (valuta / 100));
	return euro;
}


//e) Fordi det vil gi grove avrundinger pga. Int. Mer hensiktsmessig å bruke Double. 


//4) Bruk av funksjoner i funksjoner, og røtter
//a) 
double discriminant(double a, double b, double c) {
	double x1 = (pow(b, 2) - (4 * a * c));
	return x1;
}

//b) 
// kan anta at a != 0
void printRealRoots(double a, double b, double c) {
	if (discriminant(a, b, c) < 0) {
		cout << "Funksjonen har ingen løsninger." << endl;
	}
	else if (discriminant(a, b, c) > 0) {
		cout << "Funksjonen har 2 løsninger: " << endl;
		double Solution1 = (-b + sqrt(discriminant(a, b, c))) / (2 * a);
		double Solution2 = (-b - sqrt(discriminant(a, b, c))) / (2 * a);
		cout << "Løsning 1: " << Solution1 << endl;
		cout << "Løsning 2:" << Solution2 << endl;
	}
	else if (discriminant(a, b, c) == 0) {
		cout << "Funksjonen har 1 løsning: " << endl;
		double Solution1 = (-b + sqrt(discriminant(a, b, c))) / (2 * a);
		cout << "Løsning:" << Solution1 << endl;
	}
}


//c)
void solveQuadraticEquation() {
	double x1;
	double x2;
	double x3;
	cout << "Skriv inn det første av tre desimaltall: " << endl;
	cin >> x1;
	cout << "" << endl;
	cout << "Skriv inn det andre av tre desimaltall: " << endl;
	cin >> x2;
	cout << "" << endl;
	cout << "Skriv inn det siste desimaltallet: " << endl;
	cin >> x3;
	cout << "" << endl;
	cout << "De tre desimaltallene dine er: " << x1 << ", " << x2 << ", og " << x3 << "." << endl;
	printRealRoots(x1, x2, x3);
}

//3b)
void multiplikasjon() {
	int bredde;
	int høyde;
	cout << "Ønsket høyde: " << endl;
	cin >> høyde;
	cout << "Ønsket bredde: " << endl;
	cin >> bredde;
	for (int i = 1; i < høyde + 1; ++i) { 
		for (int x = 1; x < bredde + 1; ++x) { 
			cout << i * x << '\t';
		}
		cout << endl;
	
	}
}
//"\t" //linjeskifte for tabulator 

int main() {
	
	setlocale(LC_ALL, "");
	int x = 1;
	while (x != 0) {
		cout << "Velg hvilken funksjon du ønsker å kjøre." << endl;
		cout << "0) Avlsutt" << endl;
		cout << "1) Summer to tall" << endl;
		cout << "2) Summer flere tall" << endl;
		cout << "3) Konverter NOK til Euro" << endl;
		cout << "4) Løs Andregradslikningen" << endl;
		cout << "5) Multiplikasjon" << endl;
		cout << "6) Printer et heltall" << endl;
		cout << "7) Printer et heltall" << endl;
		cout << "8) Sjekker om tall er oddetall" << endl;
		cout << "9) Konverterer sekunder til timer, minutter og sekunder" << endl;
		cout << "10) Skriv inn desimaltall" << endl;
		cout << "11) Discriminant" << endl;
		cout << "12) PrintRealRoots" << endl;
		cout << "" << endl;
		cin >> x;

		switch (x) {

		case 0:
			cout << "Programmet avsluttes." << endl;
			break;

		case 1:
			int numbers;
			cout << "Summer to tall" << endl;
			numbers = inputIntegersAndPrintSum();
			cout << "Addisjon av dine to heltall blir: " << numbers << endl;
			break;

		case 2:
			inputIntegersUsingLoopAndPrintSum();
			break;

		case 3:
			double numr;
			cout << "Konverter NOK til EURO" << endl;
			numr = nokTilEuro();
			cout << fixed;
			cout << "Beløpet ditt blir " << setprecision(2) << numr << " Euro med en valutakurs på 9.7358." << endl;
			break;

		case 4:
			solveQuadraticEquation();
			break;
		case 5:
			multiplikasjon();
			break;
		case 6:
			inputAndPrintInteger();
			break;
		case 7:
		//Når man har mer enn én setning i case må man bruke krøllparenteser
		{int number = inputInteger();
		cout << "Du skrev: " << number << endl; }
			break;
		case 8:
			cout << isOdd(15);
			break;
		case 9:
			printHumanReadableTime(3661);
			break;
		case 10:
		{double num = inputDouble();
		cout << "Du skrev flyttallet: " << num << endl; }
			break;
		case 11:
			cout << "Discriminant " << " : " << discriminant(1.0, 2.0, 1.0) << endl;
			break;
		case 12:
		{cout << "printRealRoots:" << endl;
		printRealRoots(1.0, 2.0, 1.0); }
			break;

		}
	}

	return 0;
}
