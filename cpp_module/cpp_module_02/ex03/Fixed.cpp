#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() :_fixedPointNum(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const int d )
{
	// std::cout << "Int constructor called" << std::endl;
	setRawBits(d << _fractionalBit);
}

Fixed::Fixed( const float f )
{
	// std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(f * (1 << _fractionalBit)));
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
	return ((float)getRawBits() / (1 << _fractionalBit));
}

int Fixed::toInt( void ) const
{
	return (getRawBits() / (1 << _fractionalBit));
}

Fixed &Fixed::operator=(const Fixed &ref)
{
	// std::cout << "Copy assignment operator called" << std::endl;
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
	return (!(operator==(ref)));
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
	temp.setRawBits(((int64_t)getRawBits() * ref.getRawBits()) >> _fractionalBit);
	return (temp);
}

Fixed Fixed::operator/(const Fixed &ref) const
{
	Fixed temp;
	temp.setRawBits(((int64_t)getRawBits() << 8) / ref.getRawBits());
	return (temp);
}


// [ Increment, decrement ]

Fixed &Fixed::operator++( void )
{
	setRawBits(getRawBits() + 1);
	return (*this);
}

Fixed &Fixed::operator--( void )
{
	setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed temp(*this);
	operator++();
	return (temp);
}

Fixed Fixed::operator--( int )
{
	Fixed temp(*this);
	operator--();
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