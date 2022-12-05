#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a(2.0f, 0.0f);
	Point b(0.0f, 2.0f);
	Point c(0.0f, 0.0f);
	Point point (1.0f, 1.0f);
	Point d;
	d = b;
	std::cout << b.getPointY().getRawBits() << std::endl;
	std::cout << d.getPointY().getRawBits() << std::endl;

	if (bsp(a, b, c, point) == true)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	return (0);
}