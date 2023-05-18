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

const char *RPN::InvalidInputException::what() const throw() {
	return "Error : Invalid input";
}

const char *RPN::DivisionByZeroException::what() const throw() {
	return "Error : Division By Zero is undefined";
}

int RPN::calc() {
	std::stack<int> numbers;
	int first(0), second(0), res(0);

	validCheck();
	for (unsigned int i = 0; i < _expression.length(); i += 2) {
		if (std::isdigit(_expression[i])) {
			numbers.push(_expression[i] - '0');
		}
		else if (isOperation(_expression[i])) {
			if (numbers.empty())
				throw InvalidInputException();
			second = numbers.top();
			numbers.pop();
			if (numbers.empty())
				throw InvalidInputException();
			first = numbers.top();
			numbers.pop();
			if (_expression[i] == '*') {
				res = first * second;
			}
			else if (_expression[i] == '/') {
				if (second == 0) {
					std::cout << "[" << i << "]";
					throw DivisionByZeroException();
				}
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
	}
	if (numbers.size() != 1) {
		throw InvalidInputException();
	}
	res = numbers.top();
	return res;
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
	if (_expression[_expression.length() - 1] == ' ')
		throw InvalidInputException();
	for (unsigned int i = 0; i < _expression.length(); i++) {
		if (i & 1 && _expression[i] != ' ')
			throw InvalidInputException();
		if (i & 0 && (!isOperation(_expression[i]) || !std::isdigit(_expression[i]))) {
				throw InvalidInputException();
		}
	}
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