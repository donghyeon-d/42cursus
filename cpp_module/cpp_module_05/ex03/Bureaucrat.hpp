#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private :
        const std::string _name;
        int _grade;

    public :
        class GradeTooHighException : public std::exception
        {
            public :
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public :
                const char* what() const throw();
        };
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &bureaucrat);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &bureaucrat);
        std::string getName() const;
        int getGrade() const;
        void setGrade(int grade);
        void upGrade();
        void downGrade();
        void signForm(AForm &form);
        void executeForm(AForm const &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat);

#endif
