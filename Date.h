#ifndef DATE_H_
#define DATE_H_

#include<iostream>
using namespace std;

// Date class definition
class Date
{
	int day;
	int month;
	int year;
	static Date defaultDate;	// class variable shared by all objects of date class
	int checkDay(int) const;	// utility function to confirm proper day value based on month and year
	bool leapyear(int)const;	// utility function to check leap years
public:
	Date(int = 0, int = 0, int = 0);	// Constructor
	Date(const Date &);			// Copy Constructor

	friend ostream & operator <<(ostream &, const Date &);		// Stream Insertion
	friend istream & operator >>(istream &, Date &);			// Stream Extraction

	// setters
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setDate(int = 0, int = 0, int = 0);
	void setDate(const Date &);

	// getters
	int GET_DAY()const;
	int GET_MONTH()const;
	int GET_YEAR()const;
	const Date & GET_DATE()const;
	static Date getToDay();

	void addDay(int);
	void addMonth(int);
	void addYear(int);

	double caclAge();

	static void setDefaultDate(int = 0, int = 0, int = 0);		// default date setter function
	static const Date & getDefaultDate();						// defualt date getter function
}; // end class Date
#endif
