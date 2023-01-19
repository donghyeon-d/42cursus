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
    static int srandFlag(0);

    if (srandFlag == 0)
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        srandFlag = 1;
    }
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
        std::cout << "A Type" << std::endl;
    else if (b)
        std::cout << "B Type" << std::endl;
    else if (c)
        std::cout << "C Type" << std::endl;
    std::cout << "a : " << a << ", b : " << b << ", c : " << c << std::endl;
}

void identify(Base &p)
{
    try 
    {
        A &a = dynamic_cast<A&>(p);
        if (&a == &a)
        std::cout << "A Type" << std::endl;
        // return ;
    }
    catch (std::exception &e)
    {
        std::cout << "A error : " << e.what() << std::endl;
    }
    try 
    {
        B &b = dynamic_cast<B&>(p);
        if (&b == &b)
        std::cout << "B Type" << std::endl;
        // return ;
    }
    catch (std::exception &e)
    {
        std::cout << "B error : " << e.what() << std::endl;
    }
    try 
    {
        C &c = dynamic_cast<C&>(p);
        if (&c == &c)
        std::cout << "C Type" << std::endl;
        // return ;
    }
    catch (std::exception &e)
    {
        std::cout << "C error : " << e.what() << std::endl;
    }
}


int main()
{
    Base *base_p = generate();

    std::cout << "\n<--- pointer test --->" << std::endl;
    identify(base_p);

    std::cout << "\n<--- reference test --->" << std::endl;
    Base &base_r = *base_p;
    identify(base_r);

    std::cout << "\n<--- delete --->" << std::endl;
    delete base_p;
}
