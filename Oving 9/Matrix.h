#pragma once
#include <iostream>
#include <utility> 

class Matrix
{
private:
	double **matrix;						//Matrisen matrix, en dobbeltpeker(dvs: peker f�rst p� minneadressen til listen, deretter p� minneadressen til det �nskede elementet i listen)

	int M, N;								//Antall rader(M) og kolonner(N) i matrisen


public:
	Matrix();								//Defaultkonstrukt�r (standardkonstrukt�r)	
	
	Matrix(int nRows, int nColumns);		//Konstrukt�r

	Matrix(const Matrix & rhs);				//Kopikonstrukt�r
	
	Matrix & operator=(Matrix rhs);			//Tilordningsoperator overskrivning

	explicit Matrix(int nRows);				//explicit n�kkelordeet: gj�r at den aktuelle konstrukt�ren IKKE kan brukes til � automatisk konvertere andre typer til denn aktuelle klassen 

	~Matrix();								//Skal frigi/ slette alt dynamisk allokert minne

	double getMatrix(int row, int col) const;
	
	double setMatrix(int row, int col, double value);

	int getRows() const;

	int getColumns() const;

	bool isValid() const;

	int& operator[](int& index) const;											//overlaster [] for elementer av klassen

	//friend std::iostream& operator<<(std::iostream& os, const Matrix& mat);	//overlaster << for elementer av klassen
	

};
std::ostream& operator<<(std::ostream& os, const Matrix& mat);


