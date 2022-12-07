#ifndef FIXED_HPP
#define FIXED_HPP
// #define SIGN_BIT 0b10000000000000000000000000000000
// #define VALID_INT_RANGE 0b11111111111111111111111
// #define VALID_FRACTION_RANGE 0b11111111
#include <iostream>

class Fixed
{
	private:
		int	_fixedPointNum;
		static const int	_fractionalBit = 8;

	public:
        Fixed();
		Fixed(const Fixed &ref);
        ~Fixed();
		Fixed( const int d );
		Fixed( const float f );
		Fixed &operator=(const Fixed &ref);
		int	getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<( std::ostream& os, const Fixed &ref );

#endif