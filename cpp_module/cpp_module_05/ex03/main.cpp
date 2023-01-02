#include <iostream>
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    {
        std::cout << "< --- Intern Test --- >" << std::endl;
        AForm *newForm;
        Intern intern;
        Bureaucrat Paul("Paul", 1);
        newForm = intern.makeForm("ShrubberyCreationForm", "Tree");
        newForm->beSigned(Paul);
        newForm->execute(Paul);
        std::cout << *newForm << std::endl;
        delete newForm;

        std::cout << std::endl;
        newForm = intern.makeForm("RobotomyRequestForm", "Robotomy");
        newForm->beSigned(Paul);
        newForm->execute(Paul);
        std::cout << *newForm << std::endl;
        delete newForm;

        std::cout << std::endl;
        newForm = intern.makeForm("PresidentialPardonForm", "P");
        newForm->beSigned(Paul);
        newForm->execute(Paul);
        std::cout << *newForm << std::endl;
        delete newForm;

        std::cout << std::endl;
        newForm = intern.makeForm("WrongForm", "wrong");
    }
    // system("leaks a.out");
}