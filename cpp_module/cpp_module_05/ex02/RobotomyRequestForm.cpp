#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", ROBOTOMYREQUESTSIGN, ROBOTOMYREQUESTEXEC)
{
	std::cout << "RobotomyRequestForm()" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", ROBOTOMYREQUESTSIGN, ROBOTOMYREQUESTEXEC), _target(target)
{
	std::cout << "RobotomyRequestForm(target)" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm)
: Form("RobotomyRequestForm", ROBOTOMYREQUESTSIGN, ROBOTOMYREQUESTEXEC), _target(robotomyRequestForm.getTarget())
{
	std::cout << "RobotomyRequestForm(copy) : " << robotomyRequestForm.getName() << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "~RobotomyRequestForm()" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyRequestForm)
{
	std::cout << "Error(" << robotomyRequestForm.getName() << ") : has constant attribute" << std::endl;
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (getSigned() == false)
		std::cout << "Need sign to execute" << std::endl;
	else
	{
		try
		{
			if (executor.getGrade() > getExecuteGrade())
				throw RobotomyRequestForm::GradeTooLowException();
			std::cout << getTarget() << " has been robotomized successfully 50% of the time : " << executor.getName() << std::endl;
		
		}
		catch (RobotomyRequestForm::GradeTooLowException &exception)
		{
			std::cout << "[RobotomyRequestForm] " << executor.getName() << " is " << exception.what() << std::endl;
		}
	}
}

const char *RobotomyRequestForm::GradeTooHighException::what() const throw()
{
	return ("Too High for executing");
}

const char *RobotomyRequestForm::GradeTooLowException::what() const throw()
{
	return ("Too Low for executing");
}
