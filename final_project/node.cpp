#include "node.h"

using namespace std;

bool EmptyNode::Evaluate(const Date& date_, const string& event) const {
    return true;
}

bool DateComparisonNode::Evaluate(const Date& date_, const string& event_) const {
    switch (cmp)
    {
    case Comparison::Less:
        return date_ < date;
    case Comparison::LessOrEqual:
        return date_ <= date;
    case Comparison::Greater:
        return date_ > date;
    case Comparison::GreaterOrEqual:
        return date_ >= date;
    case Comparison::Equal:
        return date_ == date;
    case Comparison::NotEqual:
        return date_ != date;
    }
    return true;

}

bool EventComparisonNode::Evaluate(const Date& date_, const string& event_) const {
    switch (cmp)
    {
    case Comparison::Less:
        return event_ < event;
    case Comparison::LessOrEqual:
        return event_ <= event;
    case Comparison::Greater:
        return event_ > event;
    case Comparison::GreaterOrEqual:
        return event_ >= event;
    case Comparison::Equal:
        return event_ == event;
    case Comparison::NotEqual:
        return event_ != event;
    }
    return true;
}


bool LogicalOperationNode::Evaluate(const Date& date_, const string& event_) const {
    if(op == LogicalOperation::And) {
        return left->Evaluate(date_, event_) && right->Evaluate(date_, event_);
    }
    return left->Evaluate(date_, event_) || right->Evaluate(date_, event_);
}


