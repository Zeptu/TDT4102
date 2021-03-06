#include "std_lib_facilities.h"
//1) C++ --> Py
/*def is_fibonacci_number(n) :
	a = 0
	b = 1
	while b < n :
		temp = b
		b += a
		a = temp
	return b == n
print(is_fibonacci_number(3))*/

//Husk å ha main-funksjonen nederst (maskinen leser nedover), ellers vil den ikke kunne "finne" koden

//2a) Største av to tall
int maxOfTwo(int a, int b) {
	if (a > b) {
		cout << "A is greater than B" << endl;
		return a;
	}
	else {
		cout << "B is greater than or equal to A" << endl;
		return b;
	}
}

//c) Fibonacci - rekker
int fiboNacci(int n) {
	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers" << endl;
	int temp = 0;
	for (int x = 1; x < n + 1; ++x) {
		cout << x << " " << b << endl;
		temp = b;	
		b += a;
		a = temp;
	}
	cout << "------\n";
		return b;
}

//d) Sum av kvadrerte tall
int squareNumberSum(int n) {
	int totalSum = 0;
	for (int i = 0; i < n; ++i) {
		totalSum += i * i;
		cout << i * i << " " << endl;
	}
	cout << totalSum << endl;
	return totalSum;
}
//Hvorfor både cout-er man og returnerer?


//e) Trekanttall 
//Void-funksjon, returnerer ingenting
void triangleNumbersBelow(int n) {
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below" << " " << n << ":" << setw(4);
	while (acc < n) {
			cout << acc << endl;
			acc += num; 
			num += 1;
}
}

//f) Primtall 1
bool isPrime(int n) {
	for (int j = 2; j < n; ++j) {
		if (n % j == 0) {
			return false;
		}
	
	}
	return true;
	
}

//g) Primtall 2
void naivePrimeNumberSearch(int n) {
	for (int number = 2; number < n;  ++number) {
		if (isPrime(number)) {
			cout << number << " is a Prime" << endl;
		}
	}
}

//h) Største nevner mindre enn tallet selv
int findGreatestDivisor(int n) {
	for (int divisor = n - 1; divisor > 0; --divisor) {
		if (n % divisor == 0) {
			return divisor;
		}
	}
	return 0;
}

//b)
int main(){

	cout << "Oppgave a)" << endl;
	cout << maxOfTwo(5, 6) << endl;
	cout << endl;
	cout << "Oppgave c)" << endl;
	cout << fiboNacci(5) << endl;
	cout << endl;
	cout << "Oppgave d)" << endl;
	squareNumberSum(5);
	cout << endl; //hvorfor må jeg her bruke to mellomrom for å få samme effekt?
	cout << endl;
	cout << "Oppgave e)" << endl;
	triangleNumbersBelow(21);
	cout << endl; 
	cout << "Oppgave f)" << endl;
	cout << isPrime(19);
	cout << endl; //samma her ...
	cout << endl;
	cout << "Oppgave g)" << endl;
	naivePrimeNumberSearch(19);
	cout << endl;
	cout << "Oppgave h)" << endl;
	cout << findGreatestDivisor(10);

	return 0; 
}

//hvis den returner skriver den ikke ut noe inni funksjonen med mindre man c-outer det
//pss: kan ikke printe en void-funksjon, for den returnerer ingenting (opp. e og g)
//når man printer er retur-funkjson printer man den delen som returneres, men dette må man ikke gjøre siden ved å bare kalle på funksjonen så kaller man på retur-delen


