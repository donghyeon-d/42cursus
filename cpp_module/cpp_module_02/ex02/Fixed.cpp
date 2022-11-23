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

Fixed &Fixed::operator=(const Fixed &ref)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedPointNum = ref._fixedPointNum;
	return (*this);
}

std::ostream& operator<<( std::ostream& os, const Fixed &ref )
{
	os << ref.toFloat();
	return os;
}

Fixed::Fixed( const int d )
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(d);
}

Fixed::Fixed( const float f )
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(f);
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointNum >> 8);
}

void Fixed::setRawBits( int const raw )
{
	_fixedPointNum = (raw & 0b11111111111111111111111) << 8; //23bit
}

void Fixed::setRawBits( float const raw )
{
	int d(raw); // 정수 부분
	float f(raw - d); // 소수 부분 (0.xxx)
	d = (d & 0b11111111111111111111111) << 8;
	int fraction(0);
	for (int i = 0; i < 8; i++)
	{
		f *= 2;
		fraction = fraction << 1;
		if (f > 1)
		{
			fraction += 1;
			f -= 1;
		}
	}
	_fixedPointNum = d + fraction;
}

float Fixed::toFloat( void ) const
{
	int d(_fixedPointNum >> 8);

	int fraction(_fixedPointNum & 0b11111111);
	float f(0);
	for (int i = 0; i < 8; i++)
	{
		if (fraction & 1)
		{
			f += 1;
		}
			f /= 2;
			fraction >>= 1;
	}
	return (d + f);
}

int Fixed::toInt( void ) const
{
	return (_fixedPointNum >> 8);
}

bool Fixed::operator==( Fixed &ref ) const
{
	if (_fixedPointNum == ref._fixedPointNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator!=( Fixed &ref ) const
{
	return (!this->operator==(ref));
}

bool Fixed::operator>( Fixed &ref ) const
{
	if (_fixedPointNum > ref._fixedPointNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator<( Fixed &ref ) const
{
	if (_fixedPointNum < ref._fixedPointNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator>=( Fixed &ref ) const
{
	if (_fixedPointNum >= ref._fixedPointNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator<=( Fixed &ref ) const
{
	if (_fixedPointNum <= ref._fixedPointNum)
		return (true);
	else
		return (false);
}

Fixed Fixed::operator+(const Fixed &ref) const
{
	_fixedPointNum + ref._fixedPointNum
}

Fixed Fixed::operator-(const Fixed &ref) const
{
	_fixedPointNum + ref._fixedPointNum
}

Fixed Fixed::operator*(const Fixed &ref) const
{
	_fixedPointNum + ref._fixedPointNum
}

Fixed Fixed::operator/(const Fixed &ref) const
{
	_fixedPointNum + ref._fixedPointNum
}
