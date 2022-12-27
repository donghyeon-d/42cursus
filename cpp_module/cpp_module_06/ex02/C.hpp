#ifndef C_HPP
#define C_HPP
#include "Base.hpp"

class C : public Base
{
    private :
        char _type;

    public :
        C();
        ~C();
        char getType() const;
};

#endif