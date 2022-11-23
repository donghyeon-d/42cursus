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

Fixed::Fixed( const int d )
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits((d & 0b11111111111111111111111) << 8);
}

Fixed::Fixed( const float f )
{
	std::cout << "Float constructor called" << std::endl;

	int d(f); // 정수 부분
	float pointNum(f - d); // 소수 부분 (0.xxx)
	d = (d & 0b11111111111111111111111) << 8;
	int fraction(0);
	for (int i = 0; i < 8; i++)
	{
		pointNum *= 2;
		fraction = fraction << 1;
		if (pointNum > 1)
		{
			fraction += 1;
			pointNum -= 1;
		}
	}
	this->setRawBits(d + fraction);
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
	int d(getRawBits() >> 8);

	int fraction(getRawBits() & 0b11111111);
	float pointNum(0);
	for (int i = 0; i < 8; i++)
	{
		if (fraction & 1)
			pointNum += 1;
		pointNum /= 2;
		fraction >>= 1;
	}
	return (d + pointNum);
}

int Fixed::toInt( void ) const
{
	return (getRawBits() >> 8);
}

Fixed &Fixed::operator=(const Fixed &ref)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(ref.getRawBits());
	return (*this);
}

bool Fixed::operator==( Fixed &ref ) const
{
	if (getRawBits() == ref.getRawBits())
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
	if (getRawBits() > ref.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<( Fixed &ref ) const
{
	if (getRawBits() < ref.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator>=( Fixed &ref ) const
{
	if (getRawBits() >= ref.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<=( Fixed &ref ) const
{
	if (getRawBits() <= ref.getRawBits())
		return (true);
	else
		return (false);
}

Fixed Fixed::operator+(const Fixed &ref) const
{
	Fixed temp;
	temp.setRawBits(getRawBits() + ref.getRawBits());
	return (temp);
}

Fixed Fixed::operator-(const Fixed &ref) const
{
	Fixed temp;
	temp.setRawBits(getRawBits() - ref.getRawBits());
	return (temp);
}

Fixed Fixed::operator*(const Fixed &ref) const
{
	Fixed temp;
	temp.setRawBits(getRawBits() * ref.getRawBits());
	return (temp);
}

Fixed Fixed::operator/(const Fixed &ref) const
{
	Fixed temp;
	temp.setRawBits(getRawBits() / ref.getRawBits());
	return (temp);
}


std::ostream& operator<<( std::ostream& os, const Fixed &ref )
{
	os << ref.toFloat();
	return os;
}