#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point a((float)2.0, (float)0.0);
	Point b((float)0.0, (float)2.0);
	Point c((float)0.0, (float)0.0);
	Point point ((float)1.0, (float)1.0);

	if (bsp(a, b, c, point) == true)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	return (0);
}