#include "Graph.h"
#include "Simple_window.h" 
#include "Car.h"
#include "Person.h"
#include "Meeting.h"
#include "Graph.h"
#include "MeetingWindow.h"
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
int main() {
	setlocale( LC_ALL, "Norwegian" );
	
	//Test Person
	Car c1{ 2 };
	Car c2{ 3 };
	Person p1{ "Synne", "synne@gmail.com" };
	cout << p1 << endl;

	Person p2{ "Sylvia", "sylvia@gmail.som", &c1 };
	cout << p2 << endl;

	Person p3{ "Marianne", "marianne.gmail.com", &c2 };
	cout << p3 << endl;
	
	Meeting m1{ 3, 4, 6, Campus::Trondheim, "C++", &p2 };
	cout << m1 << endl;

	MeetingWindow mw1{ Point{100, 100}, 300, 300, "Hello_World" };

	gui_main();			//Lar vinduet du har laget ta over programstyringen
	

}

