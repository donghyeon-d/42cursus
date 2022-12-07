#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	{
		std::cout << "[ Subject Test ]\n" << std::endl;
	
		Fixed a;
		Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}

	{
		std::cout << "\n\n/////////////////////////////////////" << std::endl;
		std::cout << "[ Arithmetic operator Test]\n" << std::endl;
		
		Fixed plus( Fixed( 5.05f ) + Fixed( 2 ) ); std::cout << std::endl;
		Fixed minus( Fixed( 5.05f ) - Fixed( 2 ) ); std::cout << std::endl;
		Fixed multi( Fixed( 5.05f ) * Fixed( 2 ) ); std::cout << std::endl;
		Fixed div( Fixed( 5.05f ) / Fixed( 2 ) ); std::cout << std::endl;

		std::cout << "Fixed( 5.05f ) + Fixed( 2 ) = " << plus << std::endl;
		std::cout << "Fixed( 5.05f ) - Fixed( 2 ) = " << minus << std::endl;
		std::cout << "Fixed( 5.05f ) * Fixed( 2 ) = " << multi << std::endl;
		std::cout << "Fixed( 5.05f ) / Fixed( 2 ) = " << div << std::endl;
	}
	
	{
		std::cout << "\n\n/////////////////////////////////////" << std::endl;
		std::cout << "[ Comparison operator Test]\n" << std::endl;

		Fixed a(1); std::cout << std::endl;
		Fixed b(5.5f); std::cout << std::endl;
		Fixed c(5.5f); std::cout << std::endl;

		std::cout << "a : "<< a << std::endl;
		std::cout << "b : "<< b << std::endl;
		std::cout << "c : "<< c << std::endl;
		std::cout << "a > b : "; a > b ? std::cout << "true" : std::cout << "false"; std::cout << std::endl;
		std::cout << "a < b : "; a < b ? std::cout << "true" : std::cout << "false"; std::cout << std::endl;
		std::cout << "a >= b : "; a >= b ? std::cout << "true" : std::cout << "false"; std::cout << std::endl;
		std::cout << "a <= b : "; a <= b ? std::cout << "true" : std::cout << "false"; std::cout << std::endl;
		std::cout << "c <= b : "; c <= b ? std::cout << "true" : std::cout << "false"; std::cout << std::endl;
		std::cout << "a != b : "; a != b ? std::cout << "true" : std::cout << "false"; std::cout << std::endl;
		std::cout << "a == b : "; a == b ? std::cout << "true" : std::cout << "false"; std::cout << std::endl;
		std::cout << "c == b : "; c == b ? std::cout << "true" : std::cout << "false"; std::cout << std::endl;
	}

	{
		std::cout << "\n\n/////////////////////////////////////" << std::endl;
		std::cout << "[ Min, Max ]\n" << std::endl;

		Fixed a(1); std::cout << std::endl;
		Fixed b(5.5f); std::cout << std::endl;
		const Fixed c(1); std::cout << std::endl;
		const Fixed d(5.5f); std::cout << std::endl;

		std::cout << "a : " << a << ", b : " << b << std::endl;
		std::cout << "max : " << Fixed::max( a, b ) << std::endl;
		std::cout << "min : " << Fixed::min( a, b ) << std::endl;
		std::cout << "max(const) : " << Fixed::max( c, d ) << std::endl;
		std::cout << "min(const) : " << Fixed::min( c, d ) << std::endl;
	}
	return (0);
}