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
	setRawBits((d & 0b11111111111111111111111) << 8);
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
	setRawBits(d + fraction);
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
	setRawBits(ref.getRawBits());
	return (*this);
}


// [ comparison operator ] 

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


// [ Arithmetic operator ] 

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
	temp.setRawBits((getRawBits() * ref.getRawBits()) >> 8);
	return (temp);
}

Fixed Fixed::operator/(const Fixed &ref) const
{
	Fixed temp;
	temp.setRawBits((getRawBits() << 8) / ref.getRawBits());
	return (temp);
}


// [ Increment, decrement ]

Fixed &Fixed::operator++( void )
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed &Fixed::operator--( void )
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed temp(0);
	temp.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() + 1);
	return (temp);
}

Fixed Fixed::operator--( int )
{
	Fixed temp(0);
	temp.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() - 1);
	return (temp);
}


// [ Min, Max ]
Fixed &Fixed::min( Fixed &ref1, Fixed &ref2 )
{
	if (ref1.getRawBits() < ref2.getRawBits())
		return (ref1);
	else
		return (ref2);
}

Fixed &Fixed::min( const Fixed &ref1, const Fixed &ref2 )
{
	if (ref1.getRawBits() < ref2.getRawBits())
		return (const_cast<Fixed &>(ref1));
	else
		return (const_cast<Fixed &>(ref2));
}

Fixed &Fixed::max( Fixed &ref1, Fixed &ref2 )
{
	if (ref1.getRawBits() > ref2.getRawBits())
		return (ref1);
	else
		return (ref2);
}

Fixed &Fixed::max( const Fixed &ref1, const Fixed &ref2 )
{
	if (ref1.getRawBits() > ref2.getRawBits())
		return (const_cast<Fixed &>(ref1));
	else
		return (const_cast<Fixed &>(ref2));
}




std::ostream& operator<<( std::ostream& os, const Fixed &ref )
{
	os << ref.toFloat();
	return os;
}