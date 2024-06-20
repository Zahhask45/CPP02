#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
//* =============INFO================
/*  CANONIC FORM
 Class containing at least:
 1) Constructor default
 2) Copy constructor
 3) '=' Operator overload
 4) Destructor (virtual!) */
//*=================================

class Fixed
{
private:
	int fixed_point_value;
	static const int n_fracts_bits = 8;
	
public:
	Fixed(void); // Default Constructer
	Fixed(Fixed const &src); // Copy Constructer
	~Fixed(void); // Destructer

	// Operator '=' overload
	// rhs = right hand side, a constant reference to our oject instance
	// not a const function because our instance will be modified (ex: a = 14)
	// Returns a reference to allow us to do "a = b = c = d"
	// In short  the operator overload will permit us to configure what the respective operator will do between classes
	Fixed & operator=(Fixed const &rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};


#endif