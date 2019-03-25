#include<iostream>
#include<string>;
using namespace std;

class Date{
	int day;
	int month;
	int year;
	static string monthNames[13];
public:
	Date();
	Date(int,int,int);
	friend ostream &  operator<<(ostream&,Date&);
	friend bool operator==(Date& d1,Date&d2);
	friend istream & operator>>(istream &,Date& d1);
	Date operator+(int x);
	Date operator=(Date &d1);
	Date& operator--();
	Date operator--(int x);
	int Date::operator[](int x);
};