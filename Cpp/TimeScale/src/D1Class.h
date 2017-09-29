/*
 * D1Class.h
 *
 *  Created on: 28 de set de 2017
 *      Author: anderson
 */

#ifndef D1CLASS_H_
#define D1CLASS_H_

#include "BaseClass.h"

class D1Class: public BaseClass {
public:
	D1Class(int ia, double db, std::string cs) {
		//config(12, 11.11, "changed str");
		val1 = ia;
		dval1 = db;
		str1 = cs;
	}

	D1Class() {
		//config(12, 11.11, "changed str");
		val1 = 12;
		dval1 = 11.11;
		str1 = "changed str";
	}

	void config(int val, double dval, std::string strval){
		val1 = val;
		dval1 = dval;
		str1 = strval;
	}

	virtual ~D1Class();
};

#endif /* D1CLASS_H_ */
