#include <iostream>
#include <cmath>
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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &ref)
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(ref.getRawBits());
	return (*this);
}

Fixed::Fixed( const int d )
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(d * (1 << 8));
	// this->setRawBits((d & 0b11111111111111111111111) << 8);
}

Fixed::Fixed( const float f )
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(f * (1 << 8));
}

int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointNum);
}

void Fixed::setRawBits( int const raw )
{
	_fixedPointNum = raw;
}

float Fixed::toFloat( void ) const
{
	return((float)getRawBits() / (1 << 8));
}

int Fixed::toInt( void ) const
{
	return (roundf((float)getRawBits() / (1 << 8)));
}

std::ostream& operator<<( std::ostream& os, const Fixed &ref )
{
	os << ref.toFloat();
	return os;
}
