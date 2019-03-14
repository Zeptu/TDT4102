#include "Matrix.h"

//Konstrukt�r 1
Matrix::Matrix()
	: matrix{ nullptr }, N{ 0 }, M{ 0 }
{}

//Konstrukt�r 2
Matrix::Matrix(int nRows, int nColumns)
	: M {nRows}, N{ nColumns } 
{

		matrix = new double*[nRows];		//ALLOKERER MINNE //Dobbeltpeker - en peker til en peker
		for (int i = 0; i < nRows; ++i)
		{
			matrix[i] = new double[nColumns];		//ALLOKERER MINNE //Peker p� den faktiske minneadressen
			for (int j = 0; j < nColumns; ++j)
			{
				matrix[i][j] = 0;
			}
		}
}

//Konstrukt�r 3 - "funker"-Sander
 Matrix::Matrix(int nRows)	//Lag identitetsmatrisen
	:Matrix(nRows, nRows)
{
		for (int i = 0; i < nRows; ++i)
		{
			matrix[i][i] = 1;
				
		}	
};

//explicit n�kkelordeet: gj�r at den aktuelle konstrukt�ren IKKE kan brukes 
//til � automatisk konvertere andre typer til denn aktuelle klassen 

double Matrix::getMatrix(int row, int col) const
{
	return matrix[row][col];
}

double Matrix::setMatrix(int row, int col, double value)
{
	matrix[row][col] = value;
	return value;
}

int Matrix::getRows() const
{
	return M;
	std::cout << "Antall rader i matrisen er: " << M << std::endl;
}

int Matrix::getColumns() const
{
	return N;
	std::cout <<"Antall kolonner i matrisen er: " << N << std::endl;
}

//Returnere true dersom matrisen gyldig
bool Matrix::isValid() const
{
	if (matrix > 0)
	{
		return true;		
	}
	else
		return false;
}

//Overskriver []
int& Matrix::operator[](int& index) const
{
	matrix[index];

	return index;
}

//Overskriver <<
std::ostream& operator<<(std::ostream& os, const Matrix& mat)
{
	if (mat.isValid())
	{
		for (int i = 0; i < mat.getRows(); ++i)
		{
			for (int j = 0; j < mat.getColumns(); ++j)
			{
				os << mat.getMatrix(i, j) << " ";
			}
			os << std::endl;
		}
		return os;
	}
	else
	{
		os << "Matrisen er ugyldig." << std::endl;
		return os;
	}

}

//Kopikonstrukt�r for Matrix-klassen
Matrix::Matrix(const Matrix & rhs)
	: matrix{ nullptr }, M{rhs.getRows()}, N{rhs.getColumns()}
	//initialiserer matrix til nullptr for � unng� dumme feil
	//Bruker getRows og getColumns for � initialisere M og N til antall rader(M) og antall kolonner(N)
{
	if (rhs.isValid())								//Sjekker om matrisen har en gyldig verdi (dvs: matrix > 0)
	{
		matrix = new double*[M];					//Allokerer nytt minne for antall rader i matrisen
		for (int i = 0; i < M; ++i)					//Itererer rader-antall ganger
		{
			matrix[i] = new double[N] {};			//Allokerer nytt minne for antall kolonner i matrisen
			for (int j = 0; j < N; ++j)				//Itererer kolonne - antall ganger 
			{
				matrix[i][j] = rhs.matrix[i][j];	//Kopierer verdien fra matrix over til det ny objektet rhs
			}
		}
	}
}
//Kopikonstrukt�rer gir masse mening!!
/*
M� passe p� at de to objektene ikke okkuperer samme plass i minnet
Derfor allokerer vi nyttMINNE for det nye objektet
Ogs� kopierer vi VERDIEN fra det gamle objektet over til det nye objektet
*/


//Tilordningsoperator for Matrix-klassen 
//Bruker Copy-and-swap - metoden
Matrix &Matrix::operator=(Matrix rhs)		//Tar inn en rhs som cbV, tar da inn en kopi(rhs) som automatisk ioorettes med bruk av kopikonstrukt�ren
{
	//Swapper 
	std::swap(M, rhs.M);					//swapper alle medlemsvariabler  mellom objektene
											//lhs tilordnes da rhs sin data(verdier + allokasjoner)
											//rhs f�r det som skal slettes - destrukt�r kalles n�r forlater scope
	std::swap(N, rhs.N);
	std::swap(matrix, rhs.matrix);
	
	return *this;							//returnerer this, en peker til objektet

	//Hensiktsmessig � kopiere alt over til rhs fordi rhs er en LOKAL
	//MEDLEMSVARIABEL, og blir automatisk slettet n�r den f�r ut av scope
	//Alts� slipper vi � tenke p� typ deallokering av minne
}

/*
Copy-and-swap:
	- Bruker en cbV parameter for h�yreoperanden, da tar vi inn en kopi(rhs) som automatisk opprettes ved 
	bruk av kopi-konsturkt�ren.
	- Deretter swapper vi alle medlemsvariabler(inkludert pekere til allokert data) mellom de to objektene.
	Dermed f�r this (venstresiden) tilordnet h�yresidens verdier (og allokerte data), og 
	rhs ender opp med det som skal slettes. 
	Siden rhs er en lokal variabel vil destrukt�ren dens automatisk bli kalt n�r den g�r ut av scope. 
*/

//Destrukt�r
Matrix::~Matrix()
{
	delete[] matrix;
	matrix = nullptr;

}

