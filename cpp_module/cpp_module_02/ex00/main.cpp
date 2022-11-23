#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;

	a.setRawBits(0b1111111111);//10
	std::cout << a.getRawBits() << std::endl;
	a.setRawBits(0b11111111111111111111);//20
	std::cout << a.getRawBits() << std::endl;
	a.setRawBits(0b1111111111111111111111);//22
	std::cout << a.getRawBits() << std::endl;
	a.setRawBits(0b11111111111111111111111);//23
	std::cout << a.getRawBits() << std::endl;
	a.setRawBits(0b111111111111111111111111);//24
	std::cout << a.getRawBits() << std::endl;
	// Fixed a;
	// Fixed b(a);
	// Fixed c;

	// c = b;
	// std::cout << a.getRawBits() << std::endl;
	// std::cout << b.getRawBits() << std::endl;
	// std::cout << c.getRawBits() << std::endl;



	return (0);
}