#include "Fixed.hpp"

#ifndef POINT_HPP
#define POINT_HPP

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &point);
		~Point();
		Point &operator=(const Point &point);
		const Fixed &getPointX() const;
		const Fixed &getPointY() const;
};


#endif