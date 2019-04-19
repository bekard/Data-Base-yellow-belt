#pragma once

#include <string>
#include <memory>

#include "date.h"

using namespace std;

enum Comparison {
	Less, LessOrEqual, Greater,
	GreaterOrEqual, Equal, NotEqual
};

enum LogicalOperation {
	Or = 1, And
};

class Node {
public:
	virtual bool Evaluate(const Date& date, const string& event) = 0;
};

class EmptyNode : public Node {
	bool Evaluate(const Date& date, const string& event) override;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(Comparison c, const Date& d);
	bool Evaluate(const Date& date, const string& event) override;
private:
	Comparison compare_;
	Date date_;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(Comparison c, const string& s);
	bool Evaluate(const Date& date, const string& event) override;
private:
	Comparison compare_;
	string event_;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(LogicalOperation op,
		const shared_ptr<Node>& v1, const shared_ptr<Node>& v2);
	bool Evaluate(const Date& date, const string& event) override;
private:
	LogicalOperation log_op_;
	shared_ptr<Node> value1_;
	shared_ptr<Node> value2_;
};