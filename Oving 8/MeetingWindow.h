#pragma once
#include "std_lib_facilities.h"
#include "Window.h"
#include "GUI.h"
#include "Graph.h"
#include "Meeting.h"
#include "Car.h"
#include "Person.h"


using namespace Graph_lib;

class MeetingWindow : public Window
{
private:
	static constexpr int fieldH = 30;
	static constexpr int fieldW = 100;
	static constexpr int fieldPad = 100;
	static constexpr int buttonW = 40;
	static constexpr int buttonH = 30;
	static constexpr int buttonPad = 50;
	static constexpr int pad = 50;

	Button quitBtn;
	

	//In_box navn;
	//In_box epost;

public:
	MeetingWindow(Point xy, int w, int h, const string& title);

	static void cb_quit(Address, Address pw);
	

};
