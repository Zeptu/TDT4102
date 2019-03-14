#include "Dummy.h"

/*
KOPIKONSTRUKT�R for Dummy

- tar inn en const referanse
- allokerer et nytt dynamisk allokert minneomr�de
- og kopierer verdien inn i minneomr�det

*/

//Kopikonstrukt�r for Dummy - klassen
Dummy::Dummy(const Dummy& dum)
{
	this->num = new int{};							//Allokerer minne for innholdet til num
	*(this->num) = *dum.num;						//Kopierer verdien fra num til Kopierer verdier fra other til this

}

//*(this->num) deallokerer, dvs f�r INNHOLDET 

//Kopikonstrukt�rer gir masse mening!!
/*
M� passe p� at de to objektene ikke okkuperer samme plass i minnet
Derfor allokerer vi nyttMINNE for det nye objektet
Ogs� kopierer vi VERDIEN fra det gamle objektet over til det nye objektet
*/


//Overskriver TILORDNINGSOPERATOREN med copy-and-swap
Dummy &Dummy::operator=(Dummy rhs)
{
	//Tar inn en rhs som cbV
	//swap bytter om verdien p� to variabler
	//Her bruker vi swap til � bytte om verdien p� de to pekerne
	//Vi swapper verdien p� innholdet som l� p� minneadressen num - pekeren pekte til
	//med pekeren til et Dummy-element (rhs)
	swap(this->num, rhs.num);
	//Returnerer en deallokert this. Dette vil gi oss innholdet som ligger p� minneomr�det this-pekeren
	//peker til. Dette vil gi oss innholdet til Dummy-elementet. 
	return *this;
}

//Bruker dummyTest til � teste at kopikonstrukt�ren og overskrivningen av tilordningsoperatoren fungerte
//som forventet
void dummyTest()
{
	Dummy a;
	*a.num = 4;
	Dummy b{ a };
	Dummy c;
	c = a;
	std::cout << "a: " << *a.num << std::endl;
	std::cout << "b: " << *b.num << std::endl;
	std::cout << "c: " << *c.num << std::endl;
	*b.num = 3;
	*c.num = 5;
	std::cout << "a: " << *a.num << std::endl;
	std::cout << "b: " << *b.num << std::endl;
	std::cout << "c: " << *c.num << std::endl;

	std::cin.get();								//For � hindre at programmet avslutter med en gang
							
}