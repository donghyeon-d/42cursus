#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", SHRUBBERYSIGN, SHRUBBERYEXEC)
{
	std::cout << "ShrubberyCreationForm()" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", SHRUBBERYSIGN, SHRUBBERYEXEC), _target(target)
{
	std::cout << "ShrubberyCreationForm(target)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & shrubberyCreationForm)
: Form("ShrubberyCreationForm", SHRUBBERYSIGN, SHRUBBERYEXEC), _target(shrubberyCreationForm.getTarget())
{
	std::cout << "ShrubberyCreationForm(copy) : " << shrubberyCreationForm.getName() << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "~ShrubberyCreationForm()" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreationForm)
{
	std::cout << "Error(" << shrubberyCreationForm.getName() << ") : has constant attribute" << std::endl;
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (getSigned() == false)
		std::cout << "Need sign to execute" << std::endl;
	else
	{
		try
		{
			if (executor.getGrade() > getExecuteGrade())
				throw ShrubberyCreationForm::GradeTooLowException();
			std::string fileName(executor.getName() + "_shrubbery");
			std::fstream writeFile(fileName, std::fstream::out);
			if (writeFile.is_open() == false)
				std::cout << "File error : can't open" << std::endl;
			else
			{
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
				std::cout << getName() << " execute complete by " << executor.getName() << std::endl;
			}
		}
		catch (ShrubberyCreationForm::GradeTooLowException &exception)
		{
			std::cout << "[ShrubberyCreationForm] " << executor.getName() << " is " << exception.what() << std::endl;
		}
	}
}

const char *ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return ("Too High for executing");
}

const char *ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return ("Too Low for executing");
}
