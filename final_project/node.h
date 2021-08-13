#pragma once

#include <string>
#include <memory>

#include "date.h"

using namespace std;

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation {
    And,
    Or
};

class Node {
public:
    virtual bool Evaluate(const Date& date_, const string& event_) const = 0;
};

class EmptyNode : public Node {
    bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(Comparison cmp_, Date date_) : date(date_), cmp(cmp_) {}

    bool Evaluate(const Date& date_, const string& event_) const override;
private:
    const Date date;
    const Comparison cmp;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison& cmp_, const string& event_) : cmp(cmp_), event(event_) {}

    bool Evaluate(const Date& date_, const string& event_) const override;
private:
    const string event;
    const Comparison cmp;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation& op_, const shared_ptr<Node>& left_, const shared_ptr<Node> right_) : op(op_), left(left_), right(right_){}

    bool Evaluate(const Date& date_, const string& event_) const override;

private:
    const LogicalOperation op;
    const shared_ptr<Node> left, right;
};
