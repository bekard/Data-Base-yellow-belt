#pragma once

#include "date.h"

#include <functional>
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>

class Database {
public:
	void Add(const Date& date, const string& event);
	int RemoveIf
	(const function<bool(const Date& date, const string& event)>& predicate);
	vector<pair<Date, string>> FindIf
	(const function<bool(const Date& date, const string& event)>& predicate) const;
	void Print(ostream& os) const;
	pair<Date, string> Last(const Date& date) const;
private:
	map<Date, vector<string>> base;
	map<Date, set<string>> sorted_base;
};