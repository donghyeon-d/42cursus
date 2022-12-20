#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat() : no parm" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat(name, grade)" << std::endl;
	if (_grade > 150)
		GradeTooLowException();
	else if (_grade < 1)
		GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	std::cout << "Bureaucrat(copy)" << std::endl;
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "~Bureaucrat()" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{

}

Bureaucrat::getName()
{
	return (_name);
}

Bureaucrat::getGrade()
{
	return (_grade);
}

Bureaucrat::upGrade(int grade)
{
	try
	{
		_grade += grade;
		if (_grade > 150)
			GradeTooLowException();
		else if (_grade < 1)
			GradeTooHighException();
		else
			;
	}
	catch
	{

	}
}

Bureaucrat::downGrade(int grade)
{

}

static Bureaucrat::GradeTooHighException()
{

}

static Bureaucrat::GradeTooLowException()
{

}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
}