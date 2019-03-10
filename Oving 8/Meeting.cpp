#include "Meeting.h"



Meeting::Meeting(int daY, int sTime, int eTime, Campus loc, string subj, const Person* leadr)
	: day{ daY }, startTime{ sTime }, endTime{ eTime }, location{ loc }, subject{ subj }, leader{ leadr } 
{}

set <const Meeting*> Meeting::meetings;		//en peker som peker på en Klasse, har alle de verdiene

int Meeting::getDay() const
{
	return day;
}

int Meeting::getStartTime() const
{
	return startTime;
}

int Meeting::getEndTime() const
{
	return endTime;
}

Campus Meeting::getLocation() const
{
	return location;
}

string Meeting::getSubject() const
{
	return subject;
}

const Person* Meeting::getLeader() const
{
	return leader;
}

void Meeting::addParticipant(Person* p) //skal legge en peker til et Person-objekt i participants
{
	participants.insert(p);
}

vector<string> Meeting::getParticipantList() const	
{
	vector<string> deltakernavn;

	for (auto i : participants)
	{
		deltakernavn.push_back(i->getName());	//Peker på getName!! Genialt! Slipper dereferere med -> :O woah
	}
	return deltakernavn;
}

	ostream& operator<<(ostream& tekst, Campus camp)
	{
		/*tekst << CampusMap[camp];
		return tekst;*/

		switch (camp)
		{
		case Campus::Trondheim: tekst << "Trondheim";
			break;
		case Campus::Gjovik: tekst << "Gjøvik";

			break;
		case Campus::Alesund: tekst << "Ålesund";
			break;
		}
		return tekst;
	}

	ostream& operator<<(ostream& tekst, Meeting& mt)
	{
	tekst << "Subject: " << mt.getSubject() << endl;
	tekst << "Location: " << mt.getLocation() << endl;
	tekst << "Start Time: " << mt.getStartTime() << endl;
	tekst << "End Time: " << mt.getEndTime() << endl;
	tekst << "Leader: " << mt.getLeader()->getName() << endl;

	for (auto j : mt.getParticipantList())	//Legger til navn på alle deltakerne i en liste
	{
		tekst << j << endl;
	}
	return tekst;

}

vector<const Person*> Meeting::findPotentialCoDriving()
{
	vector<const Person*> celine;
	for (auto i : meetings) {
		if (i != this && i->location == this ->location)
		{
			if (getDay() == i->day)
			{
				if (abs(getEndTime() - getStartTime()) == abs((i->endTime) - (i->startTime)) < 1)
				{
					if (getLocation() == i->location)
					{
						for (auto j : i->participants)
						{
							celine.push_back(j);
						}
					}
				}
			}
		}
	}
	return celine;

}

Meeting::~Meeting()												//fjerne pekeren til objektet fra meetings
{
	meetings.erase(this);		
}
