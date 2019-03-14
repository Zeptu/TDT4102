#include "Dummy.h"

/*
KOPIKONSTRUKTØR for Dummy

- tar inn en const referanse
- allokerer et nytt dynamisk allokert minneområde
- og kopierer verdien inn i minneområdet

*/

//Kopikonstruktør for Dummy - klassen
Dummy::Dummy(const Dummy& dum)
{
	this->num = new int{};							//Allokerer minne for innholdet til num
	*(this->num) = *dum.num;						//Kopierer verdien fra num til Kopierer verdier fra other til this

}

//*(this->num) deallokerer, dvs får INNHOLDET 

//Kopikonstruktører gir masse mening!!
/*
Må passe på at de to objektene ikke okkuperer samme plass i minnet
Derfor allokerer vi nyttMINNE for det nye objektet
Også kopierer vi VERDIEN fra det gamle objektet over til det nye objektet
*/


//Overskriver TILORDNINGSOPERATOREN med copy-and-swap
Dummy &Dummy::operator=(Dummy rhs)
{
	//Tar inn en rhs som cbV
	//swap bytter om verdien på to variabler
	//Her bruker vi swap til å bytte om verdien på de to pekerne
	//Vi swapper verdien på innholdet som lå på minneadressen num - pekeren pekte til
	//med pekeren til et Dummy-element (rhs)
	swap(this->num, rhs.num);
	//Returnerer en deallokert this. Dette vil gi oss innholdet som ligger på minneområdet this-pekeren
	//peker til. Dette vil gi oss innholdet til Dummy-elementet. 
	return *this;
}

//Bruker dummyTest til å teste at kopikonstruktøren og overskrivningen av tilordningsoperatoren fungerte
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

	std::cin.get();								//For å hindre at programmet avslutter med en gang
							
}