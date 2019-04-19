#include "database.h"

void Database::Add(const Date& date, const string& event) {
	set<string>::iterator it = sorted_base[date].find(event);
	if (it == sorted_base[date].end()) {
		base[date].push_back(event);
		sorted_base[date].insert(event);
	}
}

int Database::RemoveIf
(const function<bool(const Date& date, const string& event)>& predicate) {
	map<Date, vector<string>> clone = base;
	int erased = 0;
	for (auto d : clone) {
		vector<string>& events = d.second;
		auto p = [predicate, d](const string& e) {return !predicate(d.first, e); };
		auto del = stable_partition(events.begin(), events.end(), p);
		erased += events.end() - del;
		events.erase(del, events.end());

		if (events.empty()) {
			base.erase(d.first);
			sorted_base.erase(d.first);
		}
		else {
			base[d.first] = events;
			sorted_base[d.first] = set<string>(events.begin(), events.end());
		}
	}
	return erased;
}

vector<pair<Date, string>> Database::FindIf
(const function<bool(const Date& date, const string& event)>& predicate) const {
	vector<pair<Date, string>> found;
	for (const auto& by_day : base) {
		for (const auto& one_event : by_day.second) {
			if (predicate(by_day.first, one_event)) {
				found.push_back({ by_day.first, one_event });
			}
		}
	}
	return found;
}

void Database::Print(ostream& os) const {
	for (const auto& one_date : base) {
		for (const auto& one_event : one_date.second) {
			os << one_date.first << ' ' << one_event << endl;
		}
	}
}

pair<Date, string> Database::Last(const Date& date) const {
	if (base.empty() || date < base.begin()->first) throw invalid_argument("");
	auto up = base.upper_bound(date);
	--up;
	return make_pair(up->first, *up->second.rbegin());
}
