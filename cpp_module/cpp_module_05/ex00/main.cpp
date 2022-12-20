#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    {
        std::cout << "< --- UpGrade test --- >" << std::endl;
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
        Bureaucrat D(C);
        std::cout << "Grade : " << D << std::endl;
        D.setGrade(-1);
        std::cout << "Grade : " << D << std::endl;
        D.setGrade(151);
        std::cout << "Grade : " << D << std::endl;
    }
}