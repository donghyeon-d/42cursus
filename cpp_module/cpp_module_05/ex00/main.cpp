#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    {
        try
        {
            std::cout << "< --- Instantiate test --- >" << std::endl;
            Bureaucrat A("A", -1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "\n\n< --- UpGrade test --- >" << std::endl;
        Bureaucrat A("A", 1);
        std::cout << "A Grade : " << A << std::endl;
        A.upGrade();
        std::cout << "A Grade : " << A << std::endl;
    }

    {
        std::cout << "\n\n< --- DownGrade test --- >" << std::endl;
        Bureaucrat B("B", 150);
        std::cout << "Grade : " << B << std::endl;
        B.downGrade();
        std::cout << "Grade : " << B << std::endl;
    }

    {
        std::cout << "\n\n< --- Assignment, set test --- >" << std::endl;
        Bureaucrat C("C", 10);
        std::cout << "Grade : " << C << std::endl;
        Bureaucrat D;
        D = C;
        std::cout << "Grade : " << D << std::endl;
        C.setGrade(-1);
        std::cout << "Grade : " << D << std::endl;
        C.setGrade(151);
        std::cout << "Grade : " << D << std::endl;
    }
}