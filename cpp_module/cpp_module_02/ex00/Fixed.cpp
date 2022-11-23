#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() :_fixedPointNum(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed &Fixed::operator=(const Fixed &ref)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(ref.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	// return (this->_fixedPointNum >> 8);
	return (_fixedPointNum);
}

void Fixed::setRawBits( int const raw )
{
	_fixedPointNum = raw;
	// _fixedPointNum = (raw & 0b11111111111111111111111) << 8; //23bit
}

// int	Fixed::getRawBits( void ) const
// {
// 	std::cout << "getRawBits member function called" << std::endl;
// 	return (this->_fixedPointNum >> 8);
// }

// void Fixed::setRawBits( int const raw )
// {
// 	// int num(0);
// 	// int pos(0);
// 	// while ((raw >> (pos + 1)) > 0)
// 	// {
// 	// 	num += raw & (1 << pos);
// 	// 	pos++;
// 	// }
// 	_fixedPointNum = (raw & 0b11111111111111111111111) << 8; //23bit
// }