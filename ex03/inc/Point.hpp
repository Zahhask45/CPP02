#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point(void);
	Point(float const a, float const b);
	Point(Point const &src);
	~Point();

	Point & operator=(Point &rhs);

	Fixed getY(void) const;
	Fixed getX(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif