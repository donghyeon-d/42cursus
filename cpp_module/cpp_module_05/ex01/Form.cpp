#include "Form.hpp"

Form::Form()
	: _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "Form() : no name" << std::endl;
}

Form::Form(const Form &form)
	: _name(form.getName()), _signed(form.getSigned()), _signGrade(form.getSignGrade()), _executeGrade(form.getExecuteGrade())
{
	std::cout << "Form(copy)" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Form() : name " << _name << std::endl;
}

Form::~Form()
{
	std::cout << "~Form()" << std::endl;
}

Form &Form::operator=(const Form &form)
{
	std::cout << form.getName() << "has constant attributes" << std::endl;
	return (*this);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Too High for signing");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Too Low for signing");
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getSignGrade() const
{
	return (_signGrade);
}
int Form::getExecuteGrade() const
{
	return (_executeGrade);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (_signed == true)
		std::cout << "[Form] " << "already signed" << std::endl;
	else
	{
		try
		{
			if (bureaucrat.getGrade() > getSignGrade())
				throw Form::GradeTooLowException();
			_signed = true;
		}
		catch (Form::GradeTooLowException &exception)
		{
			std::cout << "[Form] " << exception.what() << std::endl;
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Form &form)
{
	os << "Form info : Name(" << form.getName() << "), Signed(" << form.getSigned() 
	<< "), Sign grade(" << form.getSignGrade() << "), Execute grade(" << form.getExecuteGrade()
	<< ")";
	return (os);
}