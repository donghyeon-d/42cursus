#include <iostream>
#include "B.hpp"

B::B() : _type('B')
{
    std::cout << "B()" << std::endl;
}

B::~B()
{
    std::cout << "~B()" << std::endl;
}

char B::getType() const
{
    return (_type);
}
