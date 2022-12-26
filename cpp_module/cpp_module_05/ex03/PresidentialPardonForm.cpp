#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", PRESIDENTIALPARDONSIGN, PRESIDENTIALPARDONEXEC)
{
	std::cout << "PresidentialPardonForm()" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", PRESIDENTIALPARDONSIGN, PRESIDENTIALPARDONEXEC), _target(target)
{
	std::cout << "PresidentialPardonForm(target)" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm)
: Form("PresidentialPardonForm", PRESIDENTIALPARDONSIGN, PRESIDENTIALPARDONEXEC), _target(presidentialPardonForm.getTarget())
{
	std::cout << "PresidentialPardonForm(copy) : " << presidentialPardonForm.getName() << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "~PresidentialPardonForm()" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialPardonForm)
{
	std::cout << "Error(" << presidentialPardonForm.getName() << ") : has constant attribute" << std::endl;
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (getSigned() == false)
		std::cout << "Need sign to execute" << std::endl;
	else
	{
		try
		{
			if (executor.getGrade() > getExecuteGrade())
				throw PresidentialPardonForm::GradeTooLowException();
			std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox : " << executor.getName() << std::endl;
		
		}
		catch (PresidentialPardonForm::GradeTooLowException &exception)
		{
			std::cout << "[PresidentialPardonForm] " << executor.getName() << " is " << exception.what() << std::endl;
		}
	}
}

const char *PresidentialPardonForm::GradeTooHighException::what() const throw()
{
	return ("Too High for executing");
}

const char *PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return ("Too Low for executing");
}
