#include "Point.hpp"

//A = (1/2)|x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2)

float area(Point a, Point b, Point c){
	float x1 = a.getX().toFloat();
	float y1 = a.getY().toFloat();
	float x2 = b.getX().toFloat();
	float y2 = b.getY().toFloat();
	float x3 = c.getX().toFloat();
	float y3 = c.getY().toFloat();
	
	float area = (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0;
	if (area >= 0.0f) // 0.0f is to compare with the 0 float
		return area;
	return area * -1;
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	float main_area = area(a, b, c);
	float area1 = area(a, b, point);
	float area2 = area(a, point, c);
	float area3 = area(point, b, c);

	 if (area1 == 0 || area2 == 0 || area3 == 0)
        return false;

	return (main_area == area1 + area2 + area3);
}