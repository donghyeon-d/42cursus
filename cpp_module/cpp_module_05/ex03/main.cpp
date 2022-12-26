#include <iostream>
#include "Form.hpp"
#include "Intern.hpp"

int main()
{
    {
        std::cout << "< --- Intern Test --- >" << std::endl;
        Form *newForm;
        Intern intern;
        Bureaucrat Paul("Paul", 1);
        newForm = intern.makeForm("ShrubberyCreationForm", "Tree");
        newForm->beSigned(Paul);
        newForm->execute(Paul);
        delete newForm;

        std::cout << std::endl;
        newForm = intern.makeForm("RobotomyRequestForm", "Robotomy");
        newForm->beSigned(Paul);
        newForm->execute(Paul);
        delete newForm;

        std::cout << std::endl;
        newForm = intern.makeForm("PresidentialPardonForm", "P");
        newForm->beSigned(Paul);
        newForm->execute(Paul);
        delete newForm;

        std::cout << std::endl;
        newForm = intern.makeForm("WrongForm", "wrong");
        delete newForm;
    }
    // system("leaks a.out");
}