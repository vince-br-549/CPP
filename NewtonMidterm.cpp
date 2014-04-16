//============================================================================
// Name        : NewtonMidterm.cpp
// Author      : Vince Herried
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
//============================================================================
// Name        : Newtons.cpp
// Author      : Vince Herried
// Version     : 1.0
// Copyright   : All rights reserved
// Description : use Netwtons method to approximate the value of a function
// online  practice exercises Coursera calculus course week nine.
// To run this program you must set the varaiables x0,--- x5, know0,know1
// and the value of the first approximation an.
// see the  comment block SETUP below
//============================================================================
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <fenv.h>
using namespace std;
bool debug = false;
static float x5 = 0, x4 = 0, x3 = 0, x2 = 0, x1 = 0, x0 = 0;

float fx(float x) {
	float temp;
	/*
	 * This is f(x)
	 *	temp = x5 * pow(x, 5) + x4 * pow(x, 4) + x3 * pow(x, 3) + x2 * pow(x, 2)
	 + x1 * pow(x, 1) + x0;
	 */

	temp = pow(x, 2) - 7 * x / 16 + 4 * x - 2 * sqrt(4 * x - 1);

	if (debug) {
		cout << "debug: at f(" << x << ") = " << temp << endl;
	}
	return temp;
}
float fpx(float x) {
	float temp;
	/*
	 * this is the first derivative of f(x), namely f'(x)

	 temp = x5 * 5 * pow(x, 4) + x4 * 4 * pow(x, 3) + x3 * 3 * pow(x, 2)
	 + x2 * 2 * pow(x, 1) + x1;
	 */
	temp = 2 * x + 57 / 16 - 4 / (sqrt(4 * x - 1));
	if (debug) {
		cout << "debug:  f'(" << x << ") = " << temp << endl;
	}
	return temp;
}
/*
 string superscript(string str) {
 str = str.replace(str.begin(),str.end(),"0", "⁰");
 str = str.replace(str.begin(),str.end(),"1", "¹");
 str = str.replaceAll("2", "²");
 str = str.replaceAll("3", "³");
 str = str.replaceAll("4", "⁴");
 str = str.replaceAll("5", "⁵");
 str = str.replaceAll("6", "⁶");
 str = str.replaceAll("7", "⁷");
 str = str.replaceAll("8", "⁸");
 str = str.replaceAll("9", "⁹");
 return str;
 }
 */

string superscript(string str) {

	str = str.replace(str.begin(), str.end(), "0", "⁰");
	str = str.replace(str.begin(), str.end(), "1", "¹");
	str = str.replace(str.begin(), str.end(), "2", "²");
	str = str.replace(str.begin(), str.end(), "3", "³");
	str = str.replace(str.begin(), str.end(), "4", "⁴");
	str = str.replace(str.begin(), str.end(), "5", "⁵");
	str = str.replace(str.begin(), str.end(), "6", "⁶");
	str = str.replace(str.begin(), str.end(), "7", "⁷");
	str = str.replace(str.begin(), str.end(), "8", "⁸");
	str = str.replace(str.begin(), str.end(), "9", "⁹");
	return str;
}

int main() {
	bool Known = false;
	int i, steps;
	float an, know0, know1, result0, result1;
	// float epsilon = 0.0001;
	feenableexcept(FE_DIVBYZERO | FE_INVALID | FE_OVERFLOW);

	/*
	 * Newton's approximation method  is a way to gather successive
	 * values in approximating a function's root.
	 * It is given by xn+1 = xn - f(xn) / f'(xn)
	 */

	/*
	 * start of SETUP where you must set the values specific
	 * to your function
	 *
	 * f(x) coefficients are set as follows, say f(x) = 3x^2 -x +7
	 * then set x5 through x3 equal to zero, and
	 * x2=3, x1=-1, and x0=7
	 */
	x5 = 0.0;
	x4 = 2.0;
	x3 = 0;
	x2 = 10.0;
	x1 = 0.0;
	x0 = -5.0;
	/*
	 * known values for f(x), f(know0) must equal result0 and f(know1) must equal result1
	 * or there is a problem with the function definition
	 */
	know0 = 0;
	result0 = +8;

	know1 = 1;
	result1 = 0;

	an = 0; // start first approximation here

	steps = 10; // number of steps to approximate

	/*
	 * end of setup,
	 * you should not need to change anything below this line
	 *
	 */

	cout << "Corsera Calculus 1 week 9 Newtons method for approximation";
	cout << "\nEvaluating the  polynomial ";

	bool showme = false;
	if (x5 != 0) {
		cout << x5 << "x^5";
		showme = true;
	}
	if (x4 != 0) {
		cout << ((x4 < 0 || showme) ? showpos : noshowpos) << x4 << "x^4";
		showme = true;
	}
	if (x3 != 0) {
		cout << ((x3 < 0 || showme) ? showpos : noshowpos) << x3 << "x^3";
		showme = true;
	}
	if (x2 != 0) {
		cout << ((x2 < 0 || showme) ? showpos : noshowpos) << x2 << "x^2";
		showme = true;
	}
	if (x1 != 0) {
		cout << ((x1 < 0 || showme) ? showpos : noshowpos) << x1 << "x";
		showme = true;
	}
	if (x0 != 0) {
		cout << showpos << x0;
	}
	cout << noshowpos << endl;
	if (Known) {
		cout << "We know that f(" << know0 << ") = " << fx(know0) << " and f("
				<< know1 << ")=" << fx(know1) << endl;

		if (fx(know0) != result0) {
			cout << "***FATAL ERROR*** The computed value for f(" << know0
					<< ") does not match the expected value of " << result0
					<< ".  Process terminated.";
			return 16;
		}

		if (fx(know1) != result1) {
			cout << "***FATAL ERROR*** The computed value for f(" << know1
					<< ") does not match the expected value of " << result1
					<< ". Process terminated.";
			return 16;
		}

	}

	cout << "\n\nStart at a0 " << "= " << an << " and calculate a2 " << endl;
	for (i = 0; i < steps; i++) {
//	while ( abs(fx(an,0)) >= epsilon ) {
		cout << "step " << i << endl;
		if (fpx(an) == 0) {
			cout
					<< "Newton's method fails because at this point the slope is zero and we get no more  points!"
					<< endl;
			return 16;
		}
		try {
			cout << "a" << i + 1 << " = " << an << "-" << fx(an) << "/"
					<< fpx(an);
			an = an - fx(an) / fpx(an);
		} catch (...) {
			cout << "fails" << endl;
		}
		cout << "=" << an << ", f(" << an << ") = " << fx(an) << endl;
	}
	return 0;
}
