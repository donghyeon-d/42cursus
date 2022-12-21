#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _executeGrade;

	public :
		class GradeTooHighException : public std::exception
		{	
			public :
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
			const char* what() const throw();
		};
		Form();
		Form(const Form &form);
		Form(std::string name, int signGrade, int executeGrade);
		~Form();
		Form &operator=(const Form &form);
		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form &form);

#endif