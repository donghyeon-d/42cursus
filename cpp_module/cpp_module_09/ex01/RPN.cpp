#include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(const char *expression) : _expression(expression) {
}

RPN::RPN(const RPN& rhs) {
	*this = rhs;
}

RPN &RPN::operator=(const RPN& rhs) {
	_expression = rhs._expression;
	return *this;
}

RPN::~RPN() {
}

int RPN::calc() {
	std::stack<int> numbers;
	int first(0), second(0), res(0);

	for (unsigned int i = 0; i < _expression.length(); i++) {
		if (std::isdigit(_expression[i])) {
			numbers.push(_expression[i] - '0');
		}
		else if (isOperation(_expression[i])) {
			second = numbers.top();
			numbers.pop();
			first = numbers.top();
			numbers.pop();
			if (_expression[i] == '*') {
				res = first * second;
			}
			else if (_expression[i] == '/') {
				res = first / second;
			}
			else if (_expression[i] == '-') {
				res = first - second;
			}
			else if (_expression[i] == '+') {
				res = first + second;
			}
			numbers.push(res);
		}
		else if (_expression[i] == ' ')
			continue ;
	}
	res = numbers.top();
	return (res);
}


std::string RPN::getExpression() {
	return _expression;
}

void RPN::setExpression(const std::string &expression) {
	_expression = expression;
}


bool RPN::validCheck() {
	if (_expression.empty() == true)
		return false;
	for (unsigned int i = 0; i < _expression.length(); i++) {
		if (i == 0 || i == 1) {
			if (std::isdigit(_expression[i]) == false) {
				return false;
			}
		}
		if (i != 0 && i % 2 == 0) {
			if (_expression[i] != ' ')
				return false;
		}
		if ((i + 1) % 4 == 0) {
			if (isOperation(_expression[i]) == false)
				return false;
		}
		if (i > 1 && (i - 1) % 4 == 0) {
			if (std::isdigit(_expression[i]) == false) {
				return false;
			}
		}
	}
	if (isOperation(_expression[_expression.length() - 1]) == false)
		return false;
	return true;
}

bool RPN::isOperation(int c) {
	if (c != '*' && \
		c != '/' && \
		c != '-' && \
		c != '+')
		return false;
	else
		return true;
}