// Example program in TDT4102_Graphics template, from PPP page 415
#include "Graph.h"
#include "Simple_window.h" 
#include "Emojii.h"

int main() {
	/*using namespace Graph_lib;
	cout << "The New \"Hello, Graphical World!\" message\n";
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Polygon poly;
	poly.add(Point{ 300, 200 });
	poly.add(Point{ 350, 100 });
	poly.add(Point{ 400, 200 });
	poly.set_color(Color::red);

	win.attach(poly);
	win.wait_for_button();*/

	// Size of window and emoji radius
	constexpr int xmax = 1000;
	constexpr int ymax = 600;
	constexpr int emojiRadius = 50;


	using namespace Graph_lib;

	const Point tl{ 100, 100 };
	const string win_label{ "Emoji factory" };
	Simple_window win{ tl, xmax, ymax, win_label };

	/* TODO:
	 *  - initialize emojis
	 *  - connect emojis to window
	**/

	EmptyFace fa1{ {200, 200}, 100 };
	fa1.attach_to(win);
	SmileyEmoji sm1{ {200, 200}, 100 };
	sm1.attach_to(win);

	EmptyFace fa2{ {200, 400}, 100 };
	fa2.attach_to(win);
	FrowningEmoji fr1{ {200, 400}, 100 };
	fr1.attach_to(win);

	EmptyFace fa3{ {200, 600}, 100 };
	fa3.attach_to(win);
	SurprisedEmoji smi1{ {200,600}, 100 };
	smi1.attach_to(win);

	EmptyFace fa4{ {400, 200}, 100 };
	fa4.attach_to(win);
	AngryEmoji an1{ {400, 200}, 100 };
	an1.attach_to(win);

	EmptyFace fa5{ {400, 400}, 100 };
	fa5.attach_to(win);
	EmojiWithGlasses gl1{ {400, 400}, 100 };
	gl1.attach_to(win);

	win.wait_for_button();

}

