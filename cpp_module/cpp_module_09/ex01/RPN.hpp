#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

class RPN {
	private:
		std::string _expression;
		bool isOperation(int c);
		bool validCheck();
		class InvalidInputException : public std::exception
        {
            public :
                const char *what() const throw();
        };
		class DivisionByZeroException : public std::exception
        {
            public :
                const char *what() const throw();
        };
	public:
		RPN();
		RPN(const char *expression);
		RPN(const RPN& rhs);
		RPN &operator=(const RPN& rhs);
		~RPN();
		int calc();
		std::string getExpression();
		void setExpression(const std::string &expression);
};

#endif
