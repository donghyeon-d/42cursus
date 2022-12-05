#include "Fixed.hpp"
#include "Point.hpp"

static float whatSide( Point const a, Point const b, Point const p )
{
	float aX, aY, bX, bY, pX, pY;

	aX = a.getPointX().toFloat();
	aY = a.getPointY().toFloat();
	bX = b.getPointX().toFloat();
	bY = b.getPointY().toFloat();
	pX = p.getPointX().toFloat();
	pY = p.getPointY().toFloat();

	return ((bY - aY) * (aX - pX) - (bX - aX) * (aY - pY));
}

static bool isSameSide( Point const a, Point const b, Point const c, Point const point)
{
	if (whatSide(a, b, c) * whatSide(a, b, point) > 0)
		return (true);
	else
		return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (isSameSide(a, b, c, point) && isSameSide(b, c, a, point) && isSameSide(c, a, b, point))
		return (true);
	else
		return (false);
}
