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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const int d )
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(d << _fractionalBit);
	// int rawBits(0);
	// int rD(d);
	// if (d < 0)
	// {
	// 	rD *= -1;
	// 	rawBits |= SIGN_BIT;
	// }
	// rawBits |= ((rD & VALID_INT_RANGE) << 8);
	// setRawBits(rawBits);
}

Fixed::Fixed( const float f )
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(f * (1 << _fractionalBit)));

	// float rFloat(f);
	// int result(0);
	// if (f < 0)
	// {
	// 	rFloat *= -1;
	// 	result |= SIGN_BIT;
	// }
	// if (f != 0)
	// {
	// 	int d(rFloat);
	// 	float pointNum(rFloat - d); // 소수 부분 (0.xxx)
	// 	d = (d & VALID_INT_RANGE) << 8;
	// 	int fraction(0);
	// 	for (int i = 0; i < 8; i++)
	// 	{
	// 		pointNum *= 2;
	// 		fraction = fraction << 1;
	// 		if (pointNum > 1)
	// 		{
	// 			fraction += 1;
	// 			pointNum -= 1;
	// 		}
	// 	}
	// 	result |= d + fraction;
	// }
	// setRawBits(result);
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
	// int rawBits(getRawBits());
	// int sign(1);
	// if (rawBits < 0)
	// {
	// 	sign = -1;
	// 	rawBits &= ~SIGN_BIT;
	// }
	// int d(rawBits >> 8);
	// int fraction(rawBits & VALID_FRACTION_RANGE);
	// float pointNum(0);
	// for (int i = 0; i < 8; i++)
	// {
	// 	if (fraction & 1)
	// 		pointNum += 1;
	// 	pointNum /= 2;
	// 	fraction >>= 1;
	// }
	// return (sign * (d + pointNum));
}

int Fixed::toInt( void ) const
{
	return (getRawBits() >> _fractionalBit);
	// if (getRawBits() < 0)
	// 	return (((getRawBits() & ~SIGN_BIT) >> 8) * -1);
	// return (getRawBits() >> 8);
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
	// int rawBit(getRawBits());
	// if (rawBit & SIGN_BIT)
	// 	rawBit--;
	// else
	// 	rawBit++;
	// if (rawBit & SIGN_BIT && (rawBit & ~SIGN_BIT) == 0)
	// 	rawBit &= ~SIGN_BIT;
	// setRawBits(rawBit);
	setRawBits(getRawBits() + 1);
	return (*this);
}

Fixed &Fixed::operator--( void )
{
	// int rawBit(getRawBits());
	// if (rawBit == 0 && !(rawBit & SIGN_BIT))
	// {
	// 	rawBit |= SIGN_BIT;
	// }
	// if (rawBit & SIGN_BIT)
	// 	rawBit++;
	// else
	// 	rawBit--;
	// if (rawBit & SIGN_BIT && (rawBit & ~SIGN_BIT) == 0)
	// 	rawBit &= ~SIGN_BIT;
	// setRawBits(rawBit);
	setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed temp(0);
	temp.setRawBits(this->getRawBits());
	operator++();
	return (temp);
}

Fixed Fixed::operator--( int )
{
	Fixed temp(0);
	temp.setRawBits(this->getRawBits());
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