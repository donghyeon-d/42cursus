#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm()" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm(target)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & shrubberyCreationForm) : Form("ShrubberyCreationForm", 145, 137), _target(shrubberyCreationForm.getTarget())
{
	std::cout << "ShrubberyCreationForm(copy) : " << shrubberyCreationForm.getName() << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "~ShrubberyCreationForm()" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreationForm)
{
	std::cout << "Error(" << shrubberyCreationForm.getName() << ") : constant attribute" << std::endl;
}

std::string ShrubberyCreationForm::getTarget()
{
	return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	if (getSigned() == false)
		
	try
	{
		if (bureaucrat.getGrade() > getSignGrade())
		std::string fileName(bureaucrat.getName() + "_shrubbery");
		std::fstream writeFile(fileName, std::fstream::out);
		if (writeFile.is_open() == false)
			std::cout << "File error : can't open" << std::endl;
		else
			writeFile
			<< "       _-_\n"
			<< "    /~~   ~~\\\n"
			<< "  /~~       ~~\\\n"
			<< " {             }\n"
			<< "  \\  _-   -_  /\n"
			<< "    ~  \\ /  ~\n"
			<< "_- -   | | _- _\n"
			<< "  _ -  | |   -_\n"
			<< "      /\\ /\\" << std::endl;
	}
}

const char *ShrubberyCreationForm::GradeTooHighException::what() const
{

}

const char *ShrubberyCreationForm::GradeTooLowException::what() const
{

}
