#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
		AForm();
		AForm(const AForm &form);
		AForm(std::string name, int signGrade, int executeGrade);
		virtual ~AForm();
		AForm &operator=(const AForm &form);
		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm &Aform);

#endif