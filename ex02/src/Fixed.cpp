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
}

Fixed::Fixed( Fixed const & src){
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & rhs){
	setRawBits(rhs.getRawBits());
	return (*this);
}

Fixed::~Fixed(void){
}


Fixed::Fixed(const int n){
	setRawBits(n << this->n_fracts_bits);
}

Fixed::Fixed(const float n){
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
	return o;
}

// Ex02 starts here

bool Fixed::operator>(Fixed const & rhs){
	return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const & rhs){
	return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const & rhs){
		return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const & rhs){
		return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const & rhs){
		return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const & rhs){
		return this->getRawBits() != rhs.getRawBits();
}


Fixed Fixed::operator+(Fixed const & rhs) const{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const & rhs) const{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const & rhs) const{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const & rhs) const{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed & Fixed::operator--(void){
	this->fixed_point_value -= 1;
	return *this;
}
Fixed & Fixed::operator++(void){
	this->fixed_point_value += 1;
	return *this;
}
Fixed Fixed::operator--(int){
	Fixed tmp = *this;
	this->fixed_point_value -= 1;
	return tmp;
}
Fixed Fixed::operator++(int){
	Fixed tmp = *this;
	this->fixed_point_value += 1;
	return tmp;
}


Fixed & Fixed::min(Fixed & a, Fixed & b){
	if (a <= b)
		return a;
	return b;
}
Fixed & Fixed::max(Fixed & a, Fixed & b){
	if (a >= b)
		return a;
	return b;
}
Fixed const & Fixed::min(Fixed const & a, Fixed const  & b){
	if (a.getRawBits() <= b.getRawBits())
		return a;
	return b;
}
Fixed const & Fixed::max(Fixed const & a, Fixed const  & b){
	if (a.getRawBits() >= b.getRawBits())
		return a;
	return b;
}

