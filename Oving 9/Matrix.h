#pragma once
#include <iostream>
#include <utility> 

class Matrix
{
private:
	double **matrix;	//Matrisen matrix, en dobbeltpeker(dvs: peker først på minneadressen til listen, deretter på minneadressen til det ønskede elementet i listen)

	int M, N;		//Antall rader(M) og kolonner(N) i matrisen


public:
	Matrix();				//Defaultkonstruktør (standardkonstruktør)	
	
	Matrix(int nRows, int nColumns);	//Konstruktør

	Matrix(const Matrix & rhs);		//Kopikonstruktør
	
	Matrix & operator=(Matrix rhs);		//Tilordningsoperator overskrivning

	explicit Matrix(int nRows);		//explicit nøkkelordeet: gjør at den aktuelle konstruktøren IKKE kan brukes til å automatisk konvertere andre typer til denn aktuelle klassen 

	~Matrix();				//Skal frigi/ slette alt dynamisk allokert minne

	double getMatrix(int row, int col) const;
	
	double setMatrix(int row, int col, double value);

	int getRows() const;

	int getColumns() const;

	bool isValid() const;

	int& operator[](int& index) const;     //overlaster [] for elementer av klassen

	//friend std::iostream& operator<<(std::iostream& os, const Matrix& mat); //overlaster << for elementer av klassen
	
};
std::ostream& operator<<(std::ostream& os, const Matrix& mat);


