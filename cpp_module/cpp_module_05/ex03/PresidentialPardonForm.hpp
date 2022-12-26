#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONSIGN 25
#define PRESIDENTIALPARDONEXEC 5
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private :
		std::string _target;

	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm);
		PresidentialPardonForm(std::string name, int signGrade, int executeGrade);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &presidentialPardonForm);
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