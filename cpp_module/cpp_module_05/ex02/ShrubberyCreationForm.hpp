#ifndef SHRUbBERYCREATIONFORM_HPP
#define SHRUbBERYCREATIONFORM_HPP
#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);
		ShrubberyCreationForm(std::string name, int signGrade, int executeGrade);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubberyCreationForm);
		void creatShrubbery(Bureaucrat &bureaucrat) const;
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