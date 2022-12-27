#ifndef A_HPP
#define A_HPP
#include "Base.hpp"

class A : public Base
{
    private :
        char _type;

    public :
        A();
        ~A();
        char getType() const;
};

#endif