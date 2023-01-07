#include <iostream>
#include "whatever.hpp"

int main( void )
{
    {
        std::cout << "< --- int test --- >" << std::endl;
        int a = 2, b = 3;
        int &ar(a);
        int &br(b);

        ::swap( a, b );
        std::cout << "::swap(a, b)" << std::endl;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::cout << "min( ar, br ) = " << ::min( ar, br ) << std::endl;
        std::cout << "max( ar, br ) = " << ::max( ar, br ) << std::endl;
    }

{
        std::cout << "\n\n< --- const int test --- >" << std::endl;
        const int a = 2, b = 3;

        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    }

    {
        std::cout << "\n\n< --- pointer test --- >" << std::endl;
        int *ap(new int), *bp(new int);
        *ap = 1;
        *bp = 2;

        std::cout << "[original] ap = " << ap << ", bp = " << bp << std::endl;
        ::swap(ap, bp);
        std::cout << "::swap(ap, bp)" << std::endl;
        std::cout << "ap = " << ap << ", bp = " << bp << std::endl;
        std::cout << "min( ap, bp ) = " << ::min( ap, bp ) << std::endl;
        std::cout << "max( ap, bp ) = " << ::max( ap, bp ) << std::endl;
    }

    {
        std::cout << "\n\n< --- string test --- >" << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        std::cout << "[original] c = " << c << ", d = " << d << std::endl;
            std::cout << "::swap(a, b)" << std::endl;
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }

    return 0;
}