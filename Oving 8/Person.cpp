#include "Person.h"

Person::Person(string name, string email, Car* car)
	: name{ name }, email{ email }, car{ car } {}

//Benytter nullptr som defaultargument i car. Det betyr at konstrukt�ren kan brukes med bare
//de to f�rste parameternavnene, og den tredje vil da f� standardverdien sin (defaultverdien)

string Person::getName() const 
{
	return name;
}

string Person::getEmail() const
{
	return email;
}

void Person::setEmail( string nyEmail)
{
	email = nyEmail;
}

bool Person::hasAvailableSeats() const
{
	if ( car == nullptr) 
	{
		return false;
	}
	else 
	{
		return true;
	}
}

ostream& operator<<(ostream& os, const Person& person)
{
	return os << person.name << " " << person.email << endl;
}

