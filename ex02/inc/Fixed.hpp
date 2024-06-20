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
	
	bool operator>(Fixed const &rhs);
	bool operator<(Fixed const &rhs);
	bool operator>=(Fixed const &rhs);
	bool operator<=(Fixed const &rhs);
	bool operator==(Fixed const &rhs);
	bool operator!=(Fixed const &rhs);

	Fixed operator+(Fixed const &rhs) const;
	Fixed operator-(Fixed const &rhs) const;
	Fixed operator*(Fixed const &rhs) const;
	Fixed operator/(Fixed const &rhs) const;

	Fixed & operator--(void);
	Fixed & operator++(void);
	Fixed operator--(int);
	Fixed operator++(int);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	static Fixed & min(Fixed & a, Fixed & b);
	static Fixed & max(Fixed & a, Fixed & b);
	static Fixed const & min(Fixed const & a, Fixed const  & b);
	static Fixed const & max(Fixed const & a, Fixed const  & b);
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif