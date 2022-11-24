#ifndef FIXED_HPP
#define FIXED_HPP

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
		// Fixed &operator+=(const Fixed &ref) const;
		// Fixed &operator-=(const Fixed &ref) const;
		// Fixed &operator*=(const Fixed &ref) const;
		// Fixed &operator/=(const Fixed &ref) const;
};

std::ostream& operator<<( std::ostream& os, const Fixed &ref );

#endif