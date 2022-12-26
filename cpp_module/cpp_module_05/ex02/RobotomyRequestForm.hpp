#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTSIGN 72
#define ROBOTOMYREQUESTEXEC 45
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private :
		std::string _target;

	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
		RobotomyRequestForm(std::string name, int signGrade, int executeGrade);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomyRequestForm);
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