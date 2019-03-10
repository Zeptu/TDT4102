#include "MeetingWindow.h"


//MeetingWindow(int x, int y, int w, int h, const string& title) {}
//	: Window{ w, h, name }, 
//	x{}, y{}, w{}, h{}, title{},
//		navn(Point{fieldPad, pad }, fieldW, fieldH, "NAVN"),
//		email(Point{fieldPad, 2 * pad + fieldH}, fieldW, fieldH, "EPOST"),
//		addButton(Point{x_max() - pad, pad} buttonW, buttonH, "Add", cb_add)
//	{
//	attach(navn);
//	attach(epost);
//	attach(addButton);
//	attach(quitBtn);
//	}

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string & title)
	: Window{ xy, w, h, title },
	//navn(Point{ fieldPad, pad }, fieldW, fieldH, "Navn: "),
	//epost(Point{ fieldPad, pad }, fieldW, fieldH, "Epost: "),
	quitBtn{ Point{ x_max() - pad - buttonW, pad }, buttonW, buttonH, "Quit", cb_quit }
{
	attach(quitBtn);
}
	
/*{
	//attach(navn);
	//attach(epost);
	attach(quitBtn);
}*/

void MeetingWindow::cb_quit(Address, Address pw) //call back for quitBtn
	{
		reference_to<MeetingWindow>(pw).hide();
	}
