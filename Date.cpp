#include "Date.h"
#include <ctime>

// File scope starts here 

/*private static member cannot be accessed outside the class except for initialization*/
Date Date::defaultDate(7, 8, 1986);		// intitalize class variable


// Date Default + Overloaded Constructor
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
	this->setDate(d, m, y);
} // end Date constructor

// Stream Insertion
ostream & operator<<(ostream & os, const Date & d) {
	os << d.GET_DAY() << "/" << d.GET_MONTH() << "/" << d.GET_YEAR();
	return os;
} // end stream insertion

// Stream Extraction
istream & operator >>(istream & is, Date & d) {
	int dd, mm, yy;
	cout << "Enter Day: ";
	is >> dd;
	cout << "Enter Month: ";
	is >> mm;
	cout << "Enter Year: ";
	is >> yy;
	d.setDate(dd, mm, yy);

	return is;
} // end stream extraction

// function that sets day
void Date::setDay(int d) {
	this->day = this->checkDay(d);      // validate the day
} // end function setDay

// function that sets month
void Date::setMonth(int m) {
	if (m > 0 && m <= 12)
		this->month = m;
	else
		this->month = defaultDate.month;
} // end function setMonth

// function that sets year
void Date::setYear(int y) {
	if (y > 0 && y <= 3000)
		this->year = y;
	else
		this->year = defaultDate.year;
} // end function setYear

// function that sets the Date
void Date::setDate(int d, int m, int y) {
	this->setYear(y);
	this->setMonth(m);
	this->setDay(d);
} // end function setDate

// function that sets the Date
void Date::setDate(const Date &obj) {
	this->setDate(obj.GET_DAY(), obj.GET_MONTH(), obj.GET_YEAR());
} // end function setDate

// function that gets day
int Date::GET_DAY()const {
	return this->day;
} // end function GET_DAY

// function that gets month
int Date::GET_MONTH()const {
	return this->month;
} // end function GET_MONTH

// function that gets year
int Date::GET_YEAR()const {
	return this->year;
} // end function GET_YEAR

// function that gets the Date
const Date & Date::GET_DATE()const {
	return *this;
} // end function GET_DATE

// function that gets today's date
Date  Date::getToDay() {
	time_t currentTime = time(NULL);
	struct tm localTime;

	time(&currentTime);                   // Get the current time
	localtime_s(&localTime, &currentTime);  // Convert the current time to the local time

	int Day1 = localTime.tm_mday;
	int Month1 = localTime.tm_mon + 1;
	int Year1 = localTime.tm_year + 1900;
	
	Date t(Day1, Month1, Year1);
	
	return t;
} // end function getToDay

// function that adds 'x' no. of days to the date
void Date::addDay(int x) {
	static const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	for (int i = 0; i < x; i++) {
		this->day++;

		// leap year case
		if (this->month == 2 && this->day == 29 && this->leapyear(this->year))
			continue;

		// determine whether testDay is valid for specified month
		if (this->day > daysPerMonth[this->month]) {
			this->day = 1;
			this->addMonth(1);
		}
	}
} // end function addDay

// function that adds 'x' no. of months to the date
void Date::addMonth(int x) {
	for (int i = 0; i < x; i++) {
		this->month++;
		if (this->month > 12) {
			this->month = 1;
			this->addYear(1);
		}
	}
} // end function addMonth

// function that adds 'x' no. of years to the date
void Date::addYear(int x) {
	this->year += x;
	// leap year case
	if (this->day == 29 && this->month == 2 && !this->leapyear(this->year)) {
		this->day = 1;
		this->month = 3;
	}
} // end function addYear

// function that calculate age in years till to date
double Date::caclAge() {
	double y = 0.0, m= 0.0, d =0.0;
	y = getToDay().GET_YEAR() - this->GET_YEAR();
	m = getToDay().GET_MONTH() - this->GET_MONTH();
	d = getToDay().GET_DAY() - this->GET_DAY();

	m = m / 12.0;
	d = d / 365.25;
	y = y + m + d;

	return y;
} // end function caclAge

// static function that sets default date
void Date::setDefaultDate(int d, int m, int y) {
	if (d == 0)
		d = getToDay().GET_DAY();
	if (m == 0)
		m = getToDay().GET_MONTH();
	if (y == 0)
		y = getToDay().GET_YEAR();

	defaultDate.setDate(d, m, y);
} // end function setDefaultDate

  // static function that gets default date
const Date & Date::getDefaultDate() {
	return defaultDate;
}// end function getDefaultDate

// utility function to confirm proper day value based on 
// month and year; handles leap years, too
int Date::checkDay(int testDay) const {
	static const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// determine whether testDay is valid for specified month
	if (testDay > 0 && testDay <= daysPerMonth[month])
		return testDay;

	// February 29 check for leap year 
	if (month == 2 && testDay == 29 && leapyear(year))
		return testDay;

	cout << "Day " << testDay << " invalid. Set to default day.\n";

	return defaultDate.day;  // leave object in consistent state if bad value
} // end function checkDay

// utility function to check leap years
bool Date::leapyear(int y)const {
	if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
		return true;
	else
		return false;
} // end function leapyear
