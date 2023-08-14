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
	// std::cout << "Default constructor called" << std::endl;
	this->fixedPointValue = 0;
}

// destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// copy constructor
Fixed::Fixed(const Fixed& fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->setValue(fixed.getValue());
}

// copy assignment operator
Fixed& Fixed::operator=(const Fixed& fixed) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
	{
		this->fixedPointValue = fixed.getValue();
	}
	return *this;
}

Fixed::Fixed(const int int_val) : fixedPointValue(int_val << bits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_val) : fixedPointValue(roundf(float(float_val* (1 << bits))))
{
	// std::cout << "Float constructor called" << std::endl;
}

//<<演算子をオーバーロードし、float型で値を返す
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	// std::cout << "fixed.toFloat() = " << fixed.toFloat() << std::endl;
	os << fixed.toFloat();
	return os;
}

bool Fixed::operator >(const Fixed& other) const
{
	// std::cout << "Operator overload functions >" << std::endl;
	return this->fixedPointValue > other.fixedPointValue;
}
bool Fixed::operator <(const Fixed& other) const
{
	// std::cout << "Operator overload functions <" << std::endl;
	return this->fixedPointValue < other.fixedPointValue;
}
bool Fixed::operator >=(const Fixed& other) const
{
	// std::cout << "Operator overload functions >=" << std::endl;
	return this->fixedPointValue >= other.fixedPointValue;
}
bool Fixed::operator <=(const Fixed& other) const
{
	// std::cout << "Operator overload functions <=" << std::endl;
	return this->fixedPointValue <= other.fixedPointValue;
}
bool Fixed::operator ==(const Fixed& other) const
{
	// std::cout << "Operator overload functions ==" << std::endl;
	return this->fixedPointValue == other.fixedPointValue;
}
bool Fixed::operator !=(const Fixed& other) const
{
	// std::cout << "Operator overload functions !=" << std::endl;
	return this->fixedPointValue != other.fixedPointValue;
}

//TODO:ビットシフト後にインクリメント
// increment/decrement operators
Fixed& Fixed::operator++() { // pre-increment ++val
	this->fixedPointValue += 1;
	return *this;
}

Fixed Fixed::operator++(int) { // post-increment val++
	Fixed temp(*this);
	this->fixedPointValue += 1;
	return temp;
}

// increment/decrement operators
Fixed& Fixed::operator--() { // pre-increment
	this->fixedPointValue -= 1;
	return *this;
}

Fixed Fixed::operator--(int) { // post-increment
	Fixed temp(*this);
	this->fixedPointValue -= 1;
	return temp;
}

Fixed Fixed::operator +(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator -(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator *(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator /(const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.fixedPointValue < b.fixedPointValue)
		return (a);
	return (b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.fixedPointValue < b.fixedPointValue)
		return (a);
	return (b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.fixedPointValue > b.fixedPointValue)
		return (a);
	return (b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.fixedPointValue > b.fixedPointValue)
		return (a);
	return (b);
}


float Fixed::toFloat(void) const
{
	// std::cout << "(float)fixedPointValue " << (float)fixedPointValue << std::endl;
	return (float)fixedPointValue / (float)(1 << bits);
}
int Fixed::toInt(void) const
{
	// std::cout << "(int)fixedPointValue " << (int)fixedPointValue << std::endl;
	return (int)fixedPointValue / (1 << bits);
}
