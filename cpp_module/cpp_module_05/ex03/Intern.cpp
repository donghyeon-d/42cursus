#include "Intern.hpp"

Intern::Intern() : _name("intern")
{
	std::cout << "Intern()" << std::endl;
}

Intern::Intern(Intern const &intern) : _name("intern")
{
	std::cout << "Intern(copy)" << std::endl;
	*this = intern;
}

Intern::~Intern()
{
	std::cout << "~Intern()" << std::endl;
}

Intern &Intern::operator=(Intern const &intern)
{
	intern.getName();
	return (*this);
}

std::string Intern::getName() const
{
	return (_name);
}

Form *Intern::makeForm(std::string formName, std::string targetName)
{
	Form *newForm(0);
	if (formName.compare("PresidentialPardonForm") == 0)
		newForm = new PresidentialPardonForm(targetName);
	else if (formName.compare("RobotomyRequestForm") == 0)
		newForm = new RobotomyRequestForm(targetName);
	else if (formName.compare("ShrubberyCreationForm") == 0)
		newForm = new ShrubberyCreationForm(targetName);
	else
		std::cout << "Form Name doesn't exist" << std::endl;
	return (newForm);
}
