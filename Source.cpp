#include<iostream>

using namespace std;
#include "Date.h"

void main()
{
	Date::setDefaultDate();
	Date d1 = Date::getDefaultDate();
	d1.addYear(5);
	d1.addDay(27+31+28);
	cout << d1 << endl;

	system("pause");
}