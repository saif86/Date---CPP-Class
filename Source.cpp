#include<iostream>
#include "Date.h"

using namespace std;

// function main begins program execution
void main() {
	Date::setDefaultDate();
	
	Date d1 = Date::getDefaultDate();
	d1.addYear(5);
	d1.addDay(27 + 31 + 28);
	cout << d1 << endl;

	Date dob(21, 11, 1986);
	cout << "Age: " << dob.caclAge() << endl;

	system("pause");
} // end main
