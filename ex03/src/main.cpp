#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point a(0, 0);
	Point b(-2, 3);
	Point c(3, 4);
	Point point (0, 2);


	std::cout << "Point a X:" << a.getX() << std::endl;
	std::cout << "Point a Y:" << a.getY() << std::endl;
	std::cout << "Point b X:" << b.getX() << std::endl;
	std::cout << "Point b Y:" << b.getY() << std::endl;
	std::cout << "Point c X:" << c.getX() << std::endl;
	std::cout << "Point c Y:" << c.getY() << std::endl;
	std::cout << "Point X:" << point.getX() << std::endl;
	std::cout << "Point Y:" << point.getY() << std::endl << std::endl << std::endl << std::endl;


	std::cout << "Is Point inside the triangle?" << std::endl;
	if (bsp(a, b, c, point) == 1)
	{
		std::cout << "TRUE" << std::endl;
	}
	else
		std::cout << "FALSE" << std::endl;
	

	return 0;
}