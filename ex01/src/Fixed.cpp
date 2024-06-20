#include "Fixed.hpp"
#include <cmath>

const int Fixed::n_fracts_bits = 8;

int Fixed::getRawBits(void) const{
	return (this->fixed_point_value);
}

void Fixed::setRawBits(int const raw){
	this->fixed_point_value = raw;
}



Fixed::Fixed(void){
	this->fixed_point_value = 0;
	std::cout << "Default constructor called" << std::endl ;
}

Fixed::Fixed( Fixed const & src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & rhs){
	std::cout << "Assignation operator called" << std::endl;
	setRawBits(rhs.getRawBits());
	return (*this);
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const int n){
	std::cout << "Default constructor called" << std::endl ;
	setRawBits(n << this->n_fracts_bits);
}

Fixed::Fixed(const float n){
	std::cout << "Default constructor called" << std::endl ;
	setRawBits((int)roundf(n * (1 << this->n_fracts_bits))) ;
}

int Fixed::toInt(void) const{
	return this->getRawBits() >> this->n_fracts_bits;
}

float Fixed::toFloat(void) const{
	return (float)this->fixed_point_value / (1 << this->n_fracts_bits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	// std::cout << std:: endl << "RAW: " << rhs.getRawBits() << std::endl;
	// std::cout << std:: endl << "TOINT: " << rhs.toInt() << std::endl;
	// std::cout << std:: endl << "TOFLOAT: " << rhs.toFloat() << std::endl;
	return o;
}
