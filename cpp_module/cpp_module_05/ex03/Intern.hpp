#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private :
		std::string _name;

	public :
		Intern();
		Intern(Intern const &intern);
		~Intern();
		Intern &operator=(Intern const &intern);
		std::string getName() const;
		AForm *makeForm(std::string formName, std::string targetName);
};

#endif
