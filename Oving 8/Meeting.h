#pragma once
#include "std_lib_facilities.h"
#include "Person.h"

enum class Campus 
{
	Trondheim, Alesund, Gjovik
};

class Meeting 
{
private:
	int day;
	int startTime;
	int endTime;

	Campus location;
	string subject;
	const Person* leader;
	set<const Person*> participants;				//et set som best�r av pekere
	static set <const Meeting*> meetings;			//skal inneholde pekere til alle m�tene som er opprettet
	/*STATIC MEDLEMSVARIABLER: 
	- Tilh�rer klassen, ikke objektet
	- Er en felles variabel for alle objekter av klassen
	- M� initialiseres utenfor klassen*/

public:
	Meeting(int daY, int sTime, int eTime, Campus loc, string subj, const Person* leadr);

	int getDay() const;								//Get-funksjoner kan som regel v�re const //og  ha samme type som verdien de returnerer
	int getStartTime() const;
	int getEndTime() const;
	Campus getLocation() const;
	string getSubject() const;
	const Person* getLeader() const;
			
	vector<string> getParticipantList() const;		//returnerer en vector med navn p� deltakerne


	void addParticipant(Person* p);					//skal legge en peker til et Person objekt i participants

	vector<const Person*> findPotentialCoDriving();	//skal returnere en liste med Person-pekere 

	~Meeting();										//Skal fjerne pekeren til objektet fra meeting-klassen

	
};


ostream& operator<<(ostream& tekst, Campus camp);
ostream& operator<<(ostream& tekst, Meeting& mt);

/*Static: "no matter how many objects of the class are created, 
there is only one copy of the static member. A static member is shared
by all objects of the class."*/





