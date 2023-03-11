#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <cctype>

class RPN {
	private:
		std::string _expression;
		bool isOperation(int c);
	public:
		RPN();
		RPN(const char *expression);
		RPN(const RPN& rhs);
		RPN &operator=(const RPN& rhs);
		~RPN();
		bool validCheck();
		int calc();
		std::string getExpression();
		void setExpression(const std::string &expression);
};

#endif
