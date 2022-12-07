#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
// #define SIGN_BIT 0b10000000000000000000000000000000
// #define VALID_INT_RANGE 0b11111111111111111111111
// #define VALID_FRACTION_RANGE 0b11111111

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

		int	getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		Fixed &operator=(const Fixed &ref);

		// comparison operator
		bool operator==( Fixed &ref ) const;
		bool operator!=( Fixed &ref ) const;
		bool operator>( Fixed &ref ) const;
		bool operator<( Fixed &ref ) const;
		bool operator>=( Fixed &ref ) const;
		bool operator<=( Fixed &ref ) const;

		// [ Arithmetic operator ] 
		Fixed operator+( const Fixed &ref ) const;
		Fixed operator-( const Fixed &ref ) const;
		Fixed operator*( const Fixed &ref ) const;
		Fixed operator/( const Fixed &ref ) const;

		// [ Increment, decrement ]
		Fixed &operator++( void );
		Fixed &operator--( void );
		Fixed operator++( int );
		Fixed operator--( int );

		// [ Min, Max ]
		static Fixed &min( Fixed &ref1, Fixed &ref2 );
		static Fixed &min( const Fixed &ref1, const Fixed &ref2 );
		static Fixed &max( Fixed &ref1, Fixed &ref2 );
		static Fixed &max( const Fixed &ref1, const Fixed &ref2 );
};

std::ostream& operator<<( std::ostream& os, const Fixed &ref );

#endif