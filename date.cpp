#include "condition_parser.h"
#include "date.h"

void IsDash(stringstream& str, const string& line) {
	if (str.peek() != '-') {
		throw invalid_argument(line);
	}
	str.ignore(1);
}

void IsMonthValid(const int& month) {
	if (month < 1 || month > 12) {
		throw logic_error(to_string(month));
	}
}

void IsDayValid(const int& day) {
	if (day < 1 || day > 31) {
		throw runtime_error(to_string(day));
	}
}

Date::Date(const int& y, const int& m, const int& d)
	:year(y), month(m), day(d)
{
}

int Date::GetYear() const { return year; }
int Date::GetMonth() const { return month; }
int Date::GetDay() const { return day; }

ostream& operator<<(ostream& os, const Date& date) {
	os << setfill('0') << setw(4) << date.GetYear() << '-'
		<< setw(2) << date.GetMonth() << '-'
		<< setw(2) << date.GetDay();
	return os;
}

// operators

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() != rhs.GetYear()) {
		if (lhs.GetYear() < rhs.GetYear()) return true;
		return false;
	}
	if (lhs.GetMonth() != rhs.GetMonth()) {
		if (lhs.GetMonth() < rhs.GetMonth()) return true;
		return false;
	}
	if (lhs.GetDay() != rhs.GetDay()) {
		if (lhs.GetDay() < rhs.GetDay()) return true;
		return false;
	}
	return false;
}

bool operator<=(const Date& lhs, const Date& rhs) {
	return lhs < rhs || lhs == rhs;
}

bool operator>(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() != rhs.GetYear()) {
		if (lhs.GetYear() > rhs.GetYear()) return true;
		return false;
	}
	if (lhs.GetMonth() != rhs.GetMonth()) {
		if (lhs.GetMonth() > rhs.GetMonth()) return true;
		return false;
	}
	if (lhs.GetDay() != rhs.GetDay()) {
		if (lhs.GetDay() > rhs.GetDay()) return true;
		return false;
	}
	return false;
}

bool operator>=(const Date& lhs, const Date& rhs) {
	return lhs > rhs || lhs == rhs;
}

bool operator==(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear() &&
		lhs.GetMonth() == rhs.GetMonth() &&
		lhs.GetDay() == rhs.GetDay()) {
		return true;
	}
	return false;
}

bool operator!=(const Date& lhs, const Date& rhs) {
	return !(lhs == rhs);
}

Date ParseDate(istream& is) {
	string line;
	is >> line;
	stringstream str{ line };
	int y, m, d;
	str >> y;
	IsDash(str, line);
	str >> m;
	IsDash(str, line);
	str >> d;
	if (!str.eof()) throw invalid_argument(line);

	IsMonthValid(m);
	IsDayValid(d);

	return Date(y, m, d);
}