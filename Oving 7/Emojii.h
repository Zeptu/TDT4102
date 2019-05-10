#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;							// ???

class Emoji								//Emoji er en abstrakt klasse. Emoji er Baseklassen vår. 
{									//Må implementere medlemsfunksjonen attach_to()
public:
	Emoji(const Emoji&) = delete;					//Disable copying. Disable slicing, etc. //Sletter kopikonstruktøren

	Emoji& operator=(const Emoji&) = delete;			//Sletter tilordningsoperatoren i Emoji

									// Deleting the copy constructor also deletes the default constructor.
									// Emoji needs a default constructor.
	Emoji() {}							//Oppretter default konstruktør for Emoji, alternativt: ( Emoji() = default;), disse to metodene er ekvivalente
	
	virtual void attach_to(Graph_lib::Window&) = 0;	// The pure virtual function that has to be overriden for a deriving class
							// to be instantiable. Every class deriving from Emoji is supposed to
							// attach all its Shapes to a window. This makes the class abstract.

							// Relevant because Vector_ref can own Emojis and automatically cleans up.

	virtual ~Emoji() {}				//Virtuell destruktør
};

/*
VIKTIG:
- Kun Virtual-funksjoner kan overskrives
- PureVirtual-funksjoner MÅ overskrives
	->Betyr: Du får ikke bruke denne funksjoner på objekter direkte, men du kan bruke den i underklassene
*/



class Face : public Emoji				//Face er en abstrakt klasse som inneholder et tomt, gult ansikt
							//Face arver fra Emoji
{
protected:			
	Circle c1;
	Point c{ 0,0 };
	int r{ 0 };

public:
	Face(const Face&) = delete;
	Face& operator=(const Face&) = delete;
	Face() = default;

	virtual ~Face() {}

	Face(Point c, int r);						//Deklarerer konstruktør med parametre
	virtual void attach_to(Graph_lib::Window& win) override = 0;	//Deklarerer attach_to, overskriver, pure virtual
};


class EmptyFace : public Face {						//Sub-klassen EmptyFace
protected: 
	Circle e1, e2;							//Øynene

public:
	EmptyFace(Point center, int radius);				//Deklarerer konstruktør med parametre
	void attach_to(Graph_lib::Window& win) override;		//Deklarerer attach_to
};

class SmileyEmoji : public EmptyFace {
protected: 
	Arc a1;

public:
	SmileyEmoji(Point center, int radius);
	void attach_to(Graph_lib::Window& win) override;

};

class FrowningEmoji : public EmptyFace {
protected:
	Arc a2;

public:
	FrowningEmoji(Point center, int radius);
	void attach_to(Graph_lib::Window& win) override;

};

class SurprisedEmoji : public EmptyFace {
protected:
	Arc a3;

public:
	SurprisedEmoji(Point center, int radius);
	void attach_to(Graph_lib::Window& win) override;
};

class AngryEmoji : public EmptyFace {
protected:
	Arc a4;
	Line l1, l2;							//Øyenbryn

public:
	AngryEmoji(Point center, int radius);
	void attach_to(Graph_lib::Window& win) override;
};

class EmojiWithGlasses : public EmptyFace {
protected:
	Arc a5, a6, a7;							//Smilefjes og briller
	Line l3;							//Strek mellom brillene
public:
	EmojiWithGlasses(Point center, int radius);
	void attach_to(Graph_lib::Window& win) override;

};
