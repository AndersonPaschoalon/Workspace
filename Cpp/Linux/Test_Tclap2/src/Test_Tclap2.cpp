//============================================================================
// Name        : Test_Tclap2.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
#include <algorithm>
#include <tclap/CmdLine.h>

int main(int argc, char** argv) {

	try {
		TCLAP::CmdLine cmd(
				"This is the program description. I will make a template for some new commands.",
				' ', "0.9");

		TCLAP::ValueArg<std::string> nameArg("n", "name", "Name to print",
				false, "", "string");
		TCLAP::ValueArg<int> intArg("i", "int", "int arg", true, 10, "int");
		TCLAP::ValueArg<double> doubleArg("d", "double", "double arg", false,
				3.14, "double");
		TCLAP::ValueArg<std::string> strArg("s", "str", "str arg", false, "ttt",
				"string");
		TCLAP::ValueArg<std::string> name2Arg("m", "name-name",
				"Name2 to print", false, "homer2", "string");

		cmd.add(nameArg);
		cmd.add(intArg);
		cmd.add(doubleArg);
		cmd.add(strArg);
		cmd.add(name2Arg);

		TCLAP::SwitchArg boolflag("f", "flag", "bool flag", cmd, false);

		cmd.parse(argc, argv);

		std::string name = nameArg.getValue();
		int intVal = intArg.getValue();
		std::string strVal = strArg.getValue();
		double doubleVal = doubleArg.getValue();
		bool flag = boolflag.getValue();
		std::string name2 = name2Arg.getValue();

		// Do what you intend.

		if (name == "") {
			std::cerr
					<< "trace-analyzer Error: Required argument missing: trace or list.\nUse --help for help"
					<< std::endl;

			return (-1);
		}
		if (flag) {
			std::cout << "flag is active!\n";
			std::cout << "intVal:" << intVal << std::endl;
			std::cout << "strVal:" << strVal << std::endl;
			std::cout << "doubleVal:" << doubleVal << std::endl;
			std::cout << "flag:" << flag << std::endl;
			std::cout << "name-name:" << name2 << std::endl;
		} else {
			std::cout << "flag is inative :( \n";
			std::cout << "intVal:" << intVal << std::endl;
			std::cout << "strVal:" << strVal << std::endl;
			std::cout << "doubleVal:" << doubleVal << std::endl;
			std::cout << "flag:" << flag << std::endl;
			std::cout << "name-name:" << name2 << std::endl;
		}

	} catch (TCLAP::ArgException &e)  // catch any exceptions
	{
		std::cerr << "error: " << e.error() << " for arg " << e.argId()
				<< std::endl;
	}

	return (0);
}
