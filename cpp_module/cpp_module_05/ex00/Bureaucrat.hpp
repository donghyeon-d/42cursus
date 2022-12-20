#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    private :
        const std::string _name;
        int _grade;
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

    public :
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
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat);

#endif
