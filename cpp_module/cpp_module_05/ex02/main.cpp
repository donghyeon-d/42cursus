#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    {
        std::cout << "< --- Shrubbery Creation Form Test --- >" << std::endl;
        ShrubberyCreationForm Tree("Tree");
        std::cout << Tree << std::endl;
        Bureaucrat Paul("Paul", 1);
        Bureaucrat Tom("Tom", 150);
        std::cout << "- Try sign - " << std::endl;
        Tree.beSigned(Tom);
        Tree.beSigned(Paul);
        if (Tree.getSigned() == true)
            std::cout << "T sign complete" << std::endl;
        std::cout << "- Try execute - " << std::endl;
        Tree.execute(Paul);
        ShrubberyCreationForm TreeNoSigned("TreeNoSigned");
        TreeNoSigned.execute(Paul);
    }
    {
        std::cout << "\n\n< --- Robotomy Request Form Test --- >" << std::endl;
        RobotomyRequestForm Robotomy("Robotomy");
        std::cout << Robotomy << std::endl;
        Bureaucrat Paul("Paul", 1);
        Bureaucrat Tom("Tom", 150);
        std::cout << "- Try sign - " << std::endl;
        Robotomy.beSigned(Tom);
        Robotomy.beSigned(Paul);
        if (Robotomy.getSigned() == true)
            std::cout << "Robotomy sign complete" << std::endl;
        std::cout << "- Try execute - " << std::endl;
        Robotomy.execute(Paul);
        RobotomyRequestForm RobotomyNoSigned("RobotomyNoSigned");
        RobotomyNoSigned.execute(Paul);
    }
    {
        std::cout << "\n\n< --- Presidential Pardon Form Test --- >" << std::endl;
        PresidentialPardonForm PresidentialPardon("PresidentialPardon");
        std::cout << PresidentialPardon << std::endl;
        Bureaucrat Paul("Paul", 1);
        Bureaucrat Tom("Tom", 150);
        std::cout << "- Try sign - " << std::endl;
        PresidentialPardon.beSigned(Tom);
        PresidentialPardon.beSigned(Paul);
        if (PresidentialPardon.getSigned() == true)
            std::cout << "PresidentialPardon sign complete" << std::endl;
        std::cout << "- Try execute - " << std::endl;
        PresidentialPardon.execute(Paul);
        PresidentialPardonForm PresidentialPardonNoSigned("PresidentialPardonNoSigned");
        PresidentialPardonNoSigned.execute(Paul);
    }
    {
        std::cout << "\n\n< --- Bureaucrat execute form Test --- >" << std::endl;
        ShrubberyCreationForm T("T");
        RobotomyRequestForm R("R");
        PresidentialPardonForm P("P");
        Bureaucrat B("B", 1);
        B.signForm(T);
        B.signForm(R);
        B.signForm(P);
        B.executeForm(T);
        B.executeForm(R);
        B.executeForm(P);
    }
}