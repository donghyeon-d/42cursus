#include <iostream>
#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0))
{
	std::cout << "Point Default Constructor" << std::endl;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
	std::cout << "Point float Constructor" << std::endl;
}

Point::Point(const Point &pointRef)
{
	std::cout << "Point Copy Constructor" << std::endl;
	*this = pointRef;
}

Point::~Point()
{
	std::cout << "Point Destructor called" << std::endl;
}

Point &Point::operator=(const Point &pointRef)
{
	std::cout << "Point Copy assignment operator" << std::endl;
	std::cout << "X, Y are const attribute" << std::endl;
	return (*this);
}

const Fixed &Point::getPointX() const
{
	return (_x);
}

const Fixed &Point::getPointY() const
{
	return (_y);
}
