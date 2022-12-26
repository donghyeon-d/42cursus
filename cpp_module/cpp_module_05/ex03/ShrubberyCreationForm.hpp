#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYSIGN 145
#define SHRUBBERYEXEC 137
#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
	private :
		std::string _target;

	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);
		ShrubberyCreationForm(std::string name, int signGrade, int executeGrade);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubberyCreationForm);
		std::string getTarget() const;
		void execute(Bureaucrat const &bureaucrat) const;
		class GradeTooHighException : public Form::GradeTooHighException
		{	
			public :
				const char* what() const throw();
		};
		class GradeTooLowException : public Form::GradeTooLowException
		{
			public :
			const char* what() const throw();
		};
};

#endif