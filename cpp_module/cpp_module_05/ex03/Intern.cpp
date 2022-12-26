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
	std::string form[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	int i(0);
	while (i < 3 && formName.compare(form[i]) != 0)
		i++;
	switch (i)
	{
		case 0:
			newForm = new PresidentialPardonForm(targetName);
			break;
		case 1:
			newForm = new RobotomyRequestForm(targetName);
			break;
		case 2:
			newForm = new ShrubberyCreationForm(targetName);
			break;
		default:
			std::cout << "Form Name doesn't exist" << std::endl;
			break;
	}
	return (newForm);
}
