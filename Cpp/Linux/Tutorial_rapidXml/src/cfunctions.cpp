/*
 * cfunctions.c
 *
 *  Created on: 25 de abr de 2017
 *      Author: anderson
 */

#include "cfunctions.h"

void string2charvet(const string s, char* vetc) {
	strncpy(vetc, s.c_str(), sizeof(char) * CHAR_BUFFER);
	vetc[sizeof(char) * CHAR_BUFFER - 1] = '\0';
}

void charvet2type(const char* vetc, string& s) {
	char strBuffer[CHAR_BUFFER];
	strcpy(strBuffer, vetc);

}

void charvet2type(const char* vetc, int& v) {
	sscanf(vetc, "%d", &v);
}

void charvet2type(const char* vetc, long int& v) {
	sscanf(vetc, "%ld", &v);
}

void charvet2type(const char* vetc, unsigned int& v) {
	sscanf(vetc, "%d", &v);
}

void charvet2type(const char* vetc, unsigned  long int& v) {
	sscanf(vetc, "%ld", &v);
}

void charvet2type(const char* vetc, double& v) {
	sscanf(vetc, "%lf", &v);
}

void charvet2type(const char* vetc, list<double>& theList) {

	//char in_cstr[CHAR_BUFFER] = "1,223,3;4 5555 6";
	char buffer[CHAR_BUFFER];
	double val_buffer = 0;

	int buffer_conter = 0;
	int in_conter = 0;
	int out_conter = 0;

	while (1) {
		if (delimiter(vetc[in_conter]) || (vetc[in_conter] == '\0')) {
			buffer[buffer_conter] = '\0';
			buffer_conter = 0;
			sscanf(buffer, "%lf", &val_buffer);
			theList.push_back(val_buffer);
			out_conter++;
			buffer[0] = '\0';
		} else {

			buffer[buffer_conter] = vetc[in_conter];
			buffer_conter++;
		}

		if (vetc[in_conter] == '\0')
			break;
		else
			in_conter++;
	}

}

void charvet2type(const char* vetc, list<int>& theList) {

	char buffer[CHAR_BUFFER];
	int val_buffer = 0;

	int buffer_conter = 0;
	int in_conter = 0;
	int out_conter = 0;

	while (1) {
		if (delimiter(vetc[in_conter]) || (vetc[in_conter] == '\0')) {
			buffer[buffer_conter] = '\0';
			buffer_conter = 0;
			sscanf(buffer, "%d", &val_buffer);
			theList.push_back(val_buffer);
			out_conter++;
			buffer[0] = '\0';
		} else {

			buffer[buffer_conter] = vetc[in_conter];
			buffer_conter++;
		}

		if (vetc[in_conter] == '\0')
			break;
		else
			in_conter++;
	}

}

void charvet2type(const char* vetc, list<long int>& theList) {

	char buffer[CHAR_BUFFER];
	long int val_buffer = 0;

	int buffer_conter = 0;
	int in_conter = 0;
	int out_conter = 0;

	while (1) {
		if (delimiter(vetc[in_conter]) || (vetc[in_conter] == '\0')) {
			buffer[buffer_conter] = '\0';
			buffer_conter = 0;
			sscanf(buffer, "%ld", &val_buffer);
			theList.push_back(val_buffer);
			out_conter++;
			buffer[0] = '\0';
		} else {

			buffer[buffer_conter] = vetc[in_conter];
			buffer_conter++;
		}

		if (vetc[in_conter] == '\0')
			break;
		else
			in_conter++;
	}

}

bool delimiter(char c) {
	if (delimiter(c, ',') || delimiter(c, ';') || (delimiter(c, ' '))) {
		return true;
	} else {
		return (false);
	}
}

bool delimiter(char c, const char& d) {
	if (c == d) {
		return (true);
	}
	return (false);
}

template<typename T>
void printList(list<T>& theList) {

	cout << "[";
	for (typename list<T>::iterator it = theList.begin(); it != theList.end();
			it++) {
		cout << *it << ", ";
	}
	cout << "]" << endl;

}

/////////////////////

bool test_delimiter() {
	if (delimiter('c') == true)
		return (false);

	if (delimiter(',') == false)
		return (false);

	if (delimiter(' ') == false)
		return (false);

	if (delimiter(';') == false)
		return (false);

	if (delimiter('#', '#') == false)
		return (false);

	if (delimiter('-') == true)
		return (false);

	return (true);
}

bool test_charvet2type() {
	long int v_lint = 0;
	int v_int = 0;
	double v_d = 0;
	char cstr1[CHAR_BUFFER] = "1000";
	char cstr2[CHAR_BUFFER] = "10.01";

	charvet2type(cstr1, v_lint);
	charvet2type(cstr1, v_int);
	charvet2type(cstr2, v_d);

	if ((v_lint + 1) != 1001)
		return (false);
	if ((v_int + 3) != 1003)
		return (false);
	if ((v_d + 2.2) != 12.21)
		return (false);

	list<double> aList;
	list<int> aListI;
	list<long int> aListL;
	list<double> aListN;
	char in_cstrI[CHAR_BUFFER] = "1,223,3;4 5555 6";
	char in_cstrD[CHAR_BUFFER] = "1.2,2.23,3.1;4.4 5.555 6.0";
	char in_cstrN[CHAR_BUFFER] = "";

	double vd[6];
	int vi[6];
	long int vli[6];

	vi[0] = 1;
	vi[1] = 223;
	vi[2] = 3;
	vi[3] = 4;
	vi[4] = 5555;
	vi[5] = 6;

	vli[0] = 1;
	vli[1] = 223;
	vli[2] = 3;
	vli[3] = 4;
	vli[4] = 5555;
	vli[5] = 6;

	vd[0] = 1.2;
	vd[1] = 2.23;
	vd[2] = 3.1;
	vd[3] = 4.4;
	vd[4] = 5.555;
	vd[5] = 6.0;

	//printList (theList);
	charvet2type(in_cstrI, aListI);
	//printList(aListI);

	charvet2type(in_cstrD, aList);
	//printList(aList);

	charvet2type(in_cstrI, aListL);
	//printList(aListL);

	//charvet2type(in_cstrN, aListL);
	//printList(aListN);

	//double
	unsigned int i = 0;
	for (list<double>::iterator it = aList.begin(); it != aList.end(); it++) {
		//cout << vd[i] << ":" << *it << endl;
		if (vd[i] != *it) {

			return (false);
		}
		i++;
	}
	//int
	i = 0;
	for (list<int>::iterator it = aListI.begin(); it != aListI.end(); it++) {
		//cout << vi[i] << ":" << *it << endl;
		if (vi[i] != *it)
			return (false);
		i++;
	}
	//long int
	i = 0;
	for (list<long int>::iterator it = aListL.begin(); it != aListL.end();
			it++) {
		//cout << vli[i] << ":" << *it << endl;
		if (vli[i] != *it)
			return (false);
		i++;
	}


	return (true);

}

