#include "Fixed.hpp"

// Default constructor called - DONE
// Copy constructor called - DONE
// Copy assignment operator called // <-- Cette ligne est peut-etre absente
// getRawBits member function called
// Default constructor called - DONE
// Copy assignment operator called
// getRawBits member function called
// getRawBits member function called
// 0
// getRawBits member function called
// 0
// getRawBits member function called
// 0
// Destructor called - DONE
// Destructor called - DONE
// Destructor called - DONE

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_value);
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point_value = raw;
}



Fixed::Fixed(void){
	this->fixed_point_value = 17;
	std::cout << "Default constructor called" << std::endl ;
}

Fixed::Fixed( Fixed const & src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(rhs.getRawBits());
	return (*this);
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}