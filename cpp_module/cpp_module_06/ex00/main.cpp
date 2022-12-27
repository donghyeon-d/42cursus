#include <climits>
#include <iostream>
#include <sstream>
#include "Convert.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {

        Convert a(argv[1]);
        a.display();
    }


    // double a(INT_MAX);
    // std::cout << a << std::endl;
    // std::cout << (a - 2147483648) << std::endl;
    // if (a - 2147483647 > 0)
    //     std::cout << "hello]n";
    // while (1)
    // {
    //     std::string literal;
    //     std::getline(std::cin, literal);
    //     // literal.compare("")
    //     if (literal.compare("nan") == 0 | literal.compare("-inf"))

    //     float f;
    //     std::stringstream ss(literal);
    //     ss >> f;
        
    //     std::cout << "char: " << static_cast<char>(f) << std::endl;
    //     std::cout << "int: " << static_cast<int>(f) << std::endl;
    //     std::cout << "float: " << f << std::endl;
    //     std::cout << "double: " << static_cast<char>(f) << std::endl;
    // }
}