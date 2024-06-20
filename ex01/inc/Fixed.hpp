#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int fixed_point_value;
	static const int n_fracts_bits;
	
public:
	Fixed(void);
	Fixed(const int n);
	Fixed(const float n);
	Fixed(Fixed const &src);
	~Fixed(void);
	Fixed & operator=(Fixed const &rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif