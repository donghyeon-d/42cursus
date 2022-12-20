#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat() : no parm" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat(name, grade)" << std::endl;
	try
	{
		if (_grade > 150)
			throw Bureaucrat::GradeTooHighException();
		else if (_grade < 1)
			throw Bureaucrat::GradeTooLowException();
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

const char *Bureaucrat::GradeTooHighException::what() const  throw()
{
	return ("Too high");
}

const char *Bureaucrat::GradeTooLowException::what() const  throw()
{
	return ("Too Low");
}

// Bureaucrat::GradeTooHighException::~GradeTooHighException()
// {}

// Bureaucrat::GradeTooHighException::~GradeTooLowException()
// {}

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
	_grade = grade;
}

void Bureaucrat::upGrade(int grade)
{
	if (grade < 1)
		std::cout << "Grade is more than 0" << std::endl;
	else
	{
		try
		{
			if (_grade + grade > 150)
				throw Bureaucrat::GradeTooHighException();
			else if (_grade + grade < 1)
				throw Bureaucrat::GradeTooLowException();
		}
		catch (std::exception &exception)
		{
			std::cout << exception.what() << std::endl;
		}
		setGrade(getGrade() + grade);
	}
}

void Bureaucrat::downGrade(int grade)
{
if (grade < 1)
		std::cout << "Grade is more than 0" << std::endl;
	else
	{
		try
		{
			if (_grade - grade > 150)
				throw Bureaucrat::GradeTooHighException();
			else if (_grade - grade < 1)
				throw Bureaucrat::GradeTooLowException();
		}
		catch (std::exception &exception)
		{
			std::cout << exception.what() << std::endl;
		}
		setGrade(getGrade() - grade);
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (os);
}