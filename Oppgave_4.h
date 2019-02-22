#pragma once
#include "std_lib_facilities.h"

//definer typen (enum class) temps:
struct Temps {							//Husk: struct == klasse hvor alt er public ved default
	double max;
	double min;
};

istream& operator>>(istream& is, Temps& t);

void readTempsFromFile();



