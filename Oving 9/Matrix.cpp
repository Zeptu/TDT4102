#include "Matrix.h"

//Konstruktør 1
Matrix::Matrix()
	: matrix{ nullptr }, N{ 0 }, M{ 0 }
{}

//Konstruktør 2
Matrix::Matrix(int nRows, int nColumns)
	: M {nRows}, N{ nColumns } 
{

		matrix = new double*[nRows];		//ALLOKERER MINNE //Dobbeltpeker - en peker til en peker
		for (int i = 0; i < nRows; ++i)
		{
			matrix[i] = new double[nColumns];		//ALLOKERER MINNE //Peker på den faktiske minneadressen
			for (int j = 0; j < nColumns; ++j)
			{
				matrix[i][j] = 0;
			}
		}
}

//Konstruktør 3 - "funker"-Sander
 Matrix::Matrix(int nRows)	//Lag identitetsmatrisen
	:Matrix(nRows, nRows)
{
		for (int i = 0; i < nRows; ++i)
		{
			matrix[i][i] = 1;
				
		}	
};

//explicit nøkkelordeet: gjør at den aktuelle konstruktøren IKKE kan brukes 
//til å automatisk konvertere andre typer til denn aktuelle klassen 

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

//Kopikonstruktør for Matrix-klassen
Matrix::Matrix(const Matrix & rhs)
	: matrix{ nullptr }, M{rhs.getRows()}, N{rhs.getColumns()}
	//initialiserer matrix til nullptr for å unngå dumme feil
	//Bruker getRows og getColumns for å initialisere M og N til antall rader(M) og antall kolonner(N)
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
//Kopikonstruktører gir masse mening!!
/*
Må passe på at de to objektene ikke okkuperer samme plass i minnet
Derfor allokerer vi nyttMINNE for det nye objektet
Også kopierer vi VERDIEN fra det gamle objektet over til det nye objektet
*/


//Tilordningsoperator for Matrix-klassen 
//Bruker Copy-and-swap - metoden
Matrix &Matrix::operator=(Matrix rhs)		//Tar inn en rhs som cbV, tar da inn en kopi(rhs) som automatisk ioorettes med bruk av kopikonstruktøren
{
	//Swapper 
	std::swap(M, rhs.M);					//swapper alle medlemsvariabler  mellom objektene
											//lhs tilordnes da rhs sin data(verdier + allokasjoner)
											//rhs får det som skal slettes - destruktør kalles når forlater scope
	std::swap(N, rhs.N);
	std::swap(matrix, rhs.matrix);
	
	return *this;							//returnerer this, en peker til objektet

	//Hensiktsmessig å kopiere alt over til rhs fordi rhs er en LOKAL
	//MEDLEMSVARIABEL, og blir automatisk slettet når den får ut av scope
	//Altså slipper vi å tenke på typ deallokering av minne
}

/*
Copy-and-swap:
	- Bruker en cbV parameter for høyreoperanden, da tar vi inn en kopi(rhs) som automatisk opprettes ved 
	bruk av kopi-konsturktøren.
	- Deretter swapper vi alle medlemsvariabler(inkludert pekere til allokert data) mellom de to objektene.
	Dermed får this (venstresiden) tilordnet høyresidens verdier (og allokerte data), og 
	rhs ender opp med det som skal slettes. 
	Siden rhs er en lokal variabel vil destruktøren dens automatisk bli kalt når den går ut av scope. 
*/

//Destruktør
Matrix::~Matrix()
{
	delete[] matrix;
	matrix = nullptr;

}

