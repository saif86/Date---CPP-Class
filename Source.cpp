/**
* @file Source.cpp
*
* @brief This code creates Date objects and execute some
* Date members for testing prupose.
*
* @author Saif Ullah Ijaz
*
*/
#include<iostream>
#include "Date.h"

using namespace std;

// function main begins program execution
void main() {
	Date::sSetDefaultDate();

	Date d1 = Date::sGetDefaultDate();
	d1.AddYear(5);
	d1.AddDay(27 + 31 + 28);
	cout << d1 << endl;

	Date dob(21, 11, 1986);
	cout << "Age: " << dob.CaclAge() << endl;

	system("pause");
} // end main
