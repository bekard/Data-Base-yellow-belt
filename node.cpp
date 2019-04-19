#include "node.h"

template <class Comp>
bool GetComparison(const Comp& lhs, const Comp& rhs, Comparison op) {
	switch (op) {
	case Less:
		return lhs < rhs;
	case LessOrEqual:
		return lhs <= rhs;
	case Greater:
		return lhs > rhs;
	case GreaterOrEqual:
		return lhs >= rhs;
	case Equal:
		return lhs == rhs;
	case NotEqual:
		return lhs != rhs;
	}
	return false;
}

//-EmptyNode------------------------------------------------------------

bool EmptyNode::Evaluate(const Date& date, const string& event) {
	return true;
}

//-DateComparisonNode---------------------------------------------------

DateComparisonNode::DateComparisonNode(Comparison c, const Date& d)
	:compare_(c), date_(d)
{
}

bool DateComparisonNode::Evaluate
(const Date& date, const string& event) {
	return GetComparison(date, date_, compare_);
}

//-EventComparisonNode--------------------------------------------------

EventComparisonNode::EventComparisonNode(Comparison c, const string& v)
	:compare_(c), event_(v)
{
}

bool EventComparisonNode::Evaluate
(const Date& date,const string& event) {
	return GetComparison(event, event_, compare_);
}

//-LogicalOperationNode-------------------------------------------------

LogicalOperationNode::LogicalOperationNode(LogicalOperation op,
	const shared_ptr<Node>& v1, const shared_ptr<Node>& v2)
	:log_op_(op), value1_(v1), value2_(v2)
{
}

bool LogicalOperationNode::Evaluate
(const Date& date, const string& event) {
	if (log_op_ == And) {
		return value1_->Evaluate(date, event) &&
			   value2_->Evaluate(date, event);
	}
	else {
		return value1_->Evaluate(date, event) ||
			   value2_->Evaluate(date, event);
	}
}