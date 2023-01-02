#include <iostream>
#include "Form.hpp"

int main()
{
    {
        std::cout << "< --- Instantiate test --- >" << std::endl;
        try
        {
            Form A("A", -1, 1);
        }
            catch(std::exception &e)
        {
            std::cout << "Form A(\"A\", -1, 1) => " << e.what() << std::endl;
        }
        try
        {
            Form B("B", 1, 151);
        }
            catch(std::exception &e)
        {
            std::cout << "Form B(\"B\", 1, 151) => " << e.what() << std::endl;
        }
    }

    {
        try
        {
            std::cout << "\n\n< --- From.beSigned test --- >" << std::endl;
            Form A("A", 10, 10);
            Form AA(A);
            Bureaucrat B("B", 1);
            Bureaucrat C("C", 100);
            std::cout << A << std::endl;
            A.beSigned(B);
            std::cout << A << std::endl;
            A.beSigned(C); // already signed
            AA.beSigned(C); // Too low
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    {
        try
        {
            std::cout << "\n\n\n< --- Bureaucrat.signFrom test(O) --- >" << std::endl;
            Form A("A", 10, 10);
            Bureaucrat B("B", 1);
            std::cout << A << std::endl;
            B.signForm(A);
            std::cout << A << std::endl;
            B.signForm(A); // already
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    {
        try
        {
            std::cout << "\n\n\n< --- Bureaucrat.signForm text(X) --- >" << std::endl;
            Form A("A", 10, 10);
            Bureaucrat B("B", 100);
            std::cout << A << std::endl;
            B.signForm(A); // Too low
            std::cout << A << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}