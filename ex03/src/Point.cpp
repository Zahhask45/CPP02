#include "Point.hpp"

Fixed Point::getY(void) const{
	return (this->y);
}

Fixed Point::getX(void) const{
	return (this->x);
}


Point::Point(): x(0), y(0){
}

Point::Point(Point const &src): x(src.getX()), y(src.getY()){
}

Point::~Point(){
}

Point::Point(float const a, float const b): x(a), y(b){
}

Point & Point::operator=(Point & rhs){
	return (rhs);
}
