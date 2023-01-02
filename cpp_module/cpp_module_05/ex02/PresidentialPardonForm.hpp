#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONSIGN 25
#define PRESIDENTIALPARDONEXEC 5
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
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
		class GradeTooHighException : public AForm::GradeTooHighException
		{	
			public :
				const char* what() const throw();
		};
		class GradeTooLowException : public AForm::GradeTooLowException
		{
			public :
			const char* what() const throw();
		};
};

#endif