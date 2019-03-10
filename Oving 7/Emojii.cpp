#include "Emojii.h"
#include "std_lib_facilities.h"

Face::Face(Point c, int r)							//Lager kosntruktør for Face, medlemsinitialiseringsliste, Fyller ansiktet med gul
	: c1{ c, r }
{}

void Face::attach_to(Graph_lib::Window& win)		//Attacher c1 til vindu
{	
	win.attach(c1);
}

EmptyFace::EmptyFace(Point center, int radius)		//Lager kosntruktør og medlemsinitialiseringsliste
	//: Face{ center, radius }, e1{ {150, 180}, 15 }, e2{ {250, 180}, 15 }
	: Face{ center, radius }, e1{ {center.x - 50, center.y - 20}, 15 }, e2{ {center.x + 50, center.y - 20}, 15 } //Gjør plasseringen på øynene relative til plasseringen til sirkelen!!
{
	c1.set_fill_color(Color::yellow);
	e1.set_fill_color(Color::black);
	e2.set_fill_color(Color::black);
}

void EmptyFace::attach_to(Graph_lib::Window & win)	//Funksjonen kobler øynene til vinduet
{
	win.attach(c1);									//Kobler ansikt til vindu
	win.attach(e1);									//Kobler venstre øye til vindu
	win.attach(e2);									//Kobler høyre øye til vindu

}

SmileyEmoji::SmileyEmoji(Point center, int radius)
	: EmptyFace{ center, radius }, a1{ Point{200, 230}, int{ 50 }, int{ 50 }, 180, 360 }
{
	a1.set_color(Color::black);	//Farger smilet svart	
}

void SmileyEmoji::attach_to(Graph_lib::Window& win)
{
	//EmptyFace::attach_to(win);
	win.attach(a1);
}

FrowningEmoji::FrowningEmoji(Point center, int radius)
	: EmptyFace{ center, radius }, a2{ Point{200, 430}, int{ 50 }, int{ 50 }, 0, 180 }
{
	a2.set_color(Color::black);	//Farger smilet svart
}

void FrowningEmoji::attach_to(Graph_lib::Window& win)
{
	win.attach(a2);
}

SurprisedEmoji::SurprisedEmoji(Point center, int radius)
	: EmptyFace{ center, radius }, a3{ Point{200, 630}, int { 50 }, int{ 50 }, 0, 360 }
{
	a3.set_color(Color::black);
}

void SurprisedEmoji::attach_to(Graph_lib::Window& win)
{
	win.attach(a3);
}

AngryEmoji::AngryEmoji(Point center, int radius)
	: EmptyFace{ center, radius }, a4{ Point{400, 230}, int{ 50 }, int{ 50 }, 0, 180 }, l1{ Point{330, 150}, Point{380, 180} }, l2{ Point{420, 180}, Point{470, 150} }
{
	a4.set_color(Color::black);
	l1.set_color(Color::black);
	l2.set_color(Color::black);
}

void AngryEmoji::attach_to(Graph_lib::Window& win)
{
	win.attach(a4);
	win.attach(l1);
	win.attach(l2);
}

EmojiWithGlasses::EmojiWithGlasses(Point center, int radius)
	:EmptyFace{ center, radius }, a5{ Point{400, 430}, int{ 50 }, int{ 50 }, 180, 360 }, a6{ Point{350, 380}, int{ 50 }, int{ 50 }, 0, 360 }, a7{ Point{450, 380}, int{ 50 }, int{ 50 }, 0, 360 }, l3{ Point{ 373, 380 }, Point{ 427, 380 } }
{
	a5.set_color(Color::black);
	a6.set_color(Color::blue);
	a7.set_color(Color::blue);
	l3.set_color(Color::blue);
}

void EmojiWithGlasses::attach_to(Graph_lib::Window& win)
{
	win.attach(a5);
	win.attach(a6);
	win.attach(a7);
	win.attach(l3);
}
