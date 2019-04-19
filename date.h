#pragma once

#include <exception>
#include <iostream>
#include <iomanip> 
#include <sstream>
#include <string>

using namespace std;

void IsDash(stringstream& str, const string& line);
void IsMonthValid(const int& month);
void IsDayValid(const int& day);

class Date {
public:
	Date() {}
	Date(const int& y, const int& m, const int& d);
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	friend ostream& operator<<(ostream& os, const Date& date);
private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
Date ParseDate(istream& is);