#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>

class Bureaucrat
{
    private :
        const std::string _name;
        int _grade;

    public :
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &bureaucrat);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &bureaucrat);
        getName();
        getGrade();
        upGrade(int grade);
        downGrade(int grade);
        static GradeTooHighException();
        static GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat);

#endif
