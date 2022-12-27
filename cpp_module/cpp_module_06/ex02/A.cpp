#include <iostream>
#include "A.hpp"

A::A() : _type('A')
{
    std::cout << "A()" << std::endl;
}

A::~A()
{
    std::cout << "~A()" << std::endl;
}

char A::getType() const
{
    return (_type);
}
