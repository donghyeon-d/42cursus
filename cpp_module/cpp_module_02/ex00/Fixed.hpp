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
		Fixed &operator=(const Fixed &ref);
		int	getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif