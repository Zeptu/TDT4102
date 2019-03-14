#include "Fibonacci.h"
#include <iostream>



void fillInFibonacciNumbers(int result[], int length)
{
	int a{ 0 };
	int b{ 1 };
	int FibonacciNumber{ 0 };
	
	std::cout << "Fibonacci - serien: " << std::endl;

	for (int i = 0; i < length; ++i)
	{
		FibonacciNumber = a + b;
		a = b;
		b = FibonacciNumber;
		
		result[i] = FibonacciNumber;		//dytter hvert Fibonacci - element inn i listen
	}	
}

void printArray(int arr[], int length)		//Skal skrive ut length - elementer fra tabellen
{
	arr[length];
	for (int i = 0; i < length; ++i)
	{
		std::cout << arr[i] << std::endl;
	}
}

//Be brukeren om lengden på tallrekka, dynamisk allokere en tabell av riktig størrelse,
//fylle denne med tall og skrive ut. 

void createFibonacci()
{	
	int length;

	//1. Spør bruker om lengde på tallrekka
	std::cout << "Hvor mange elementer ønsker du i tallrekken?" << std::endl;
	std::cin >> length;


	//2.Allokerer minne til en tabell som er stor nok til tallrekka

	int* arr = new int[length];						//RESERVERER MINNE TIL TABELLEN arr

	//3. Fylle tabellen med fillInFibonacciNumbers()
	//4. Skriv ut resultatet til skjerm med printArray
		fillInFibonacciNumbers(arr, length);
		printArray(arr, length);


	//5. Frigjør minnet du har reservert
	delete [] arr;									//FRIGIR RESERVERT MINNE TIL TABELLEN arr
	arr = nullptr;
}

