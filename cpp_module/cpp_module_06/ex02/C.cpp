#include <iostream>
#include "C.hpp"

C::C()
{
    std::cout << "C()" << std::endl;
    _type = 'C';
}

C::~C()
{
    std::cout << "~C()" << std::endl;
}

char C::getType() const
{
    return (_type);
}
