#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat() : no parm, no grade" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat(name, grade)" << std::endl;
	try
	{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			_grade = grade;
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}
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
	std::cout << "name is constant" << std::endl;
	_grade = bureaucrat.getGrade();
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Too high. 1 <= grade <= 150");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Too Low. 1 <= grade <= 150");
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::setGrade(int grade)
{
	try
	{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			_grade = grade;
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}
}

void Bureaucrat::upGrade()
{
	try
	{
		if (_grade == 1)
			throw Bureaucrat::GradeTooHighException();
		_grade--;
	}
	catch (Bureaucrat::GradeTooHighException &exception)
	{
		std::cout << exception.what() << std::endl;
	}
}

void Bureaucrat::downGrade()
{
	try
	{
		if (_grade == 150)
			throw Bureaucrat::GradeTooLowException();
		_grade++;
	}
	catch (Bureaucrat::GradeTooLowException &exception)
	{
		std::cout << exception.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}