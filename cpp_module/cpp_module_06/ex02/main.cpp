#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    Base *newBase(0);
    int num(std::rand());
    num %= 3;
    switch (num)
    {
    case 0 :
        newBase = new A();
        break;
    case 1 :
        newBase = new B();
        break;
    case 2 :
        newBase = new C();
        break;
    default:
        break;
    }
    return (newBase);
}

void identify(Base *p)
{
    A *a = dynamic_cast<A*>(p);
    B *b = dynamic_cast<B*>(p);
    C *c = dynamic_cast<C*>(p);

    if (a)
        std::cout << a->getType() << std::endl;
    else if (b)
        std::cout << b->getType() << std::endl;
    else if (c)
        std::cout << c->getType() << std::endl;
}

void identify(Base &p)
{
    try 
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << a.getType() << std::endl;
    }
    catch (std::exception &e)
    {}
try 
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << b.getType() << std::endl;
    }
    catch (std::exception &e)
    {}
try 
    {
        C &c = dynamic_cast<C&>(p);
        std::cout << c.getType() << std::endl;
    }
    catch (std::exception &e)
    {}
}

int main()
{
    Base *base_p = generate();
    identify(base_p);
    Base &base_r = *base_p;
    identify(base_r);
}