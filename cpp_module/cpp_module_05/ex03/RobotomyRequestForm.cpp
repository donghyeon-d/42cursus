#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", ROBOTOMYREQUESTSIGN, ROBOTOMYREQUESTEXEC)
{
	std::cout << "RobotomyRequestForm()" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", ROBOTOMYREQUESTSIGN, ROBOTOMYREQUESTEXEC), _target(target)
{
	std::cout << "RobotomyRequestForm(target)" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm)
: AForm("RobotomyRequestForm", ROBOTOMYREQUESTSIGN, ROBOTOMYREQUESTEXEC), _target(robotomyRequestForm.getTarget())
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
	static int randFlag(0);
	if (getSigned() == false)
		std::cout << "Need sign to execute" << std::endl;
	else
	{
		try
		{
			if (executor.getGrade() > getExecuteGrade())
				throw RobotomyRequestForm::GradeTooLowException();
			std::cout << "drilllllll...." << std::endl;
			if (randFlag == 0)
			{
				std::srand(std::time(0));
				randFlag = 1;
			}
			int num(std::rand());
			if (num % 2)
				std::cout << getTarget() << " has been robotomized : success!!" << std::endl;
			else
				std::cout << getTarget() << " has been robotomized : fail!!" << std::endl;
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
