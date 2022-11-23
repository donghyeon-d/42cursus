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
		void setRawBits( float const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		Fixed &operator=(const Fixed &ref);

		bool operator==( Fixed &ref ) const;
		bool operator!=( Fixed &ref ) const;
		bool operator>( Fixed &ref ) const;
		bool operator<( Fixed &ref ) const;
		bool operator>=( Fixed &ref ) const;
		bool operator<=( Fixed &ref ) const;

		Fixed operator+(const Fixed &ref) const;
		Fixed operator-(const Fixed &ref) const;
		Fixed operator*(const Fixed &ref) const;
		Fixed operator/(const Fixed &ref) const;

		Fixed &operator+=(const Fixed &ref) const;
		Fixed &operator-=(const Fixed &ref) const;
		Fixed &operator*=(const Fixed &ref) const;
		Fixed &operator/=(const Fixed &ref) const;
};

std::ostream& operator<<( std::ostream& os, const Fixed &ref );

#endif