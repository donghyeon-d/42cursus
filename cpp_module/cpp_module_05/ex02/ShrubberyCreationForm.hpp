#ifndef SHRUbBERYCREATIONFORM_HPP
#define SHRUbBERYCREATIONFORM_HPP
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
		std::string getTarget();
		void execute(Bureaucrat &bureaucrat) const;
		class GradeTooHighException : public std::exception
		{	
			public :
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
			const char* what() const throw();
		};
};

#endif