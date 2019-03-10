#pragma once
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

int incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes);

void swapNumbers(int &a, int &b);

void randomizeVector(vector <int>& v, int n);

void sortVector(vector<int>& A);

double medianOfVector(const vector<int>& vektor);

string randomizeString(int lengdeCh, char upLimCh, char lowLimCh);

string readInputToString(int n, char LimCh, char lowLimCh);

int countChar(string a, char b);
