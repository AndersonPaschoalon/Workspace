//============================================================================
// Name        : Test_PlogMacros.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "PlogMacros.h"
#include <iostream>
using namespace std;

int main() {

	char* logfile = "logfile.log";
	PLOG_INIT(debug, logfile);
	PLOG_DEBUG << "Debug";
	PLOG_ERROR << "Error";

	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
