//============================================================================
// Name        : CsvCpp.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <list>
#include "CSVIterator.h"

using namespace std;



int main()
{
	std::list<uint> a;

	uint i = 0;
	std::ifstream file("plop.csv");

	for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
	{
		std::cout << i << ": " << "4th Element(" << (*loop)[3] << ")\n";
		i++;
	}
	i = 0;

	file.close();

	printf("------------------\n");
	file.open("plop.csv");

	for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
	{
		std::cout << i << ": " << "4th Element(" << (*loop)[3] << ")\n";
		i++;
	}
	i = 0;

	file.close();
	printf("------------------\n");
	file.open("plop.csv");

	std::string str;
	for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
	{
		str = (*loop)[9];

		std::cout << i << ": " << "9th Element(" << str << ")\n";
		i++;
	}
	i = 0;
	file.close();


	CsvFile file_csv("plop.csv");
	for(;;)
	{
		std::cout << i << ": " << "4th Element(" << file_csv.column(3) << ")\n";
		if( file_csv.next_line() == false ) break;
		i++;
	}
	i = 0;


	for(i = 0; i < 30; )
	{
		do
		{
			std::cout << i << ": " << "4th Element(" << file_csv.column(3) << ")\n";
			i++;
		}
		while(file_csv.next_line());
		file_csv.reset();

		//std::cout << i << ": " << "4th Element(" << file_csv.column(3) << ")\n";
		//if( !file_csv.next_line()) break;
	}




}
