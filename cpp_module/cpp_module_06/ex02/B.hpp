#ifndef B_HPP
#define B_HPP
#include "Base.hpp"

class B : public Base
{
    private :
        char _type;

    public :
        B();
        ~B();
        char getType() const;
};

#endif