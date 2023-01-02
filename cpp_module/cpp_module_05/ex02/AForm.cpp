#include "AForm.hpp"

AForm::AForm()
	: _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "AForm() : no name" << std::endl;
}

AForm::AForm(const AForm &form)
	: _name(form.getName()), _signed(form.getSigned()), _signGrade(form.getSignGrade()), _executeGrade(form.getExecuteGrade())
{
	std::cout << "AForm(copy) : constant member cannot be copied" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int executeGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "AForm() : name " << _name << std::endl;
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::~AForm()
{
	std::cout << "~AForm()" << std::endl;
}

AForm &AForm::operator=(const AForm &form)
{
	std::cout << form.getName() << "has constant attributes" << std::endl;
	return (*this);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Too High for signing");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Too Low for signing");
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getSignGrade() const
{
	return (_signGrade);
}
int AForm::getExecuteGrade() const
{
	return (_executeGrade);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (_signed == true)
		std::cout << "[" << getName() << "] already signed" << std::endl;
	else
	{
		try
		{
			if (bureaucrat.getGrade() > getSignGrade())
				throw AForm::GradeTooLowException();
			_signed = true;
		}
		catch (AForm::GradeTooLowException &exception)
		{
			std::cout << "[" << getName() << "] " << bureaucrat.getName() << " is " << exception.what() << std::endl;
		}
	}
}

std::ostream& operator<<(std::ostream& os, const AForm &form)
{
	os << "Form info : Name(" << form.getName() << "), Signed(" << form.getSigned() 
	<< "), Sign grade(" << form.getSignGrade() << "), Execute grade(" << form.getExecuteGrade()
	<< ")";
	return (os);
}