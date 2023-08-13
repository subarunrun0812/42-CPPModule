#include "Fixed.hpp"

int Fixed::getValue(void) const 
{
	return this->fixedPointValue;
}

void Fixed::setValue(int const value)
{
	this->fixedPointValue = value;
}

// default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPointValue = 0;
}

// destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// copy constructor
Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setValue(fixed.getValue());
}

// copy assignment operator
Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
	{
		this->fixedPointValue = fixed.getValue();
	}
	return *this;
}

Fixed::Fixed(const int int_val) : fixedPointValue(int_val << bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_val) : fixedPointValue(roundf(float(float_val * (1 << bits))))
{
	std::cout << "Float constructor called" << std::endl;
}

//<<演算子をオーバーロードし、float型で値を返す
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

float Fixed::toFloat(void) const
{
	/*
		fixedPointValueの実際の値を持っており、
		小数部分の256(1<<8)を割ることで、固定小数点数から浮動小数点数に変換する事が出来る
	*/
	return (float)fixedPointValue / (float)(1 << bits);
}
int Fixed::toInt(void) const
{
	return (int)fixedPointValue / (1 << bits);
}
