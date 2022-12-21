#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm()" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & shrubberyCreationForm) : Form(shrubberyCreationForm)
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

void ShrubberyCreationForm::creatShrubbery(Bureaucrat &bureaucrat) const
{
	try
	{
		if (bureaucrat.getGrade() > get)
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
