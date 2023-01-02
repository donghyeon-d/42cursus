#include <iostream>
#include "AForm.hpp"
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
        std::cout << "After Tom : " << Tree << std::endl;
        Tree.beSigned(Paul);
        std::cout << "After Paul : " << Tree << std::endl;
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
        std::cout << "After Tom : " << Robotomy << std::endl;
        Robotomy.beSigned(Paul);
        std::cout << "After Paul : " << Robotomy << std::endl;
        std::cout << "- Try execute - " << std::endl;
        Robotomy.execute(Paul);
        Robotomy.execute(Paul);
        Robotomy.execute(Paul);
        Robotomy.execute(Paul);
        Robotomy.execute(Paul);
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
        std::cout << "After Tom : " << PresidentialPardon << std::endl;
        PresidentialPardon.beSigned(Paul);
        std::cout << "After Paul : " << PresidentialPardon << std::endl;
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