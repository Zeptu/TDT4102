#include "Fibonacci.h"
#include "Matrix.h"
#include "Dummy.h"
#include <iostream>

//feilmelding: "expecting identifier" betyr at du sannsynligvis har glemt "()" på funksjonene dine

int main()
{
	setlocale( LC_ALL, "Norwegian" );
	
	//Test Fibonacci
	createFibonacci();

	//Test Matrix
	Matrix A{};
	cout << A << endl;

	Matrix B{ 3, 4 };
	cout << B << endl;

	Matrix C{ 6 };
	cout << C << endl;

	//Test Dummy
	dummyTest();
	

	std::cout << " " << std::endl;

	//Test Oppgave 4 - Kopierer verdien i A over til C, og sjekker dermed at den konstruerte kopi-konstruktøren fungerer. 
	//Dette vises ved at verdien til matrise A blir identisk med verdien til matrise C
	A = C;

	cout << "A: " << endl;
	cout << A << endl;

	cout << "C: " << endl;
	cout << C << endl;

	//Holder vinduet oppe
	system("pause");

	return 0;
}


