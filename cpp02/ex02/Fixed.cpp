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
	this->fixedPointValue = 0;
}

// destructor
Fixed::~Fixed()
{
}

// copy constructor
Fixed::Fixed(const Fixed& fixed)
{
	this->setValue(fixed.getValue());
}

// copy assignment operator
Fixed& Fixed::operator=(const Fixed& fixed) {
	if (this != &fixed)
	{
		this->fixedPointValue = fixed.getValue();
	}
	return *this;
}

Fixed::Fixed(const int int_val) : fixedPointValue(int_val << bits)
{
}

Fixed::Fixed(const float float_val) : fixedPointValue(roundf(float(float_val * (1 << bits))))
{
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
	return this->fixedPointValue > other.fixedPointValue;
}
bool Fixed::operator <(const Fixed& other) const
{
	return this->fixedPointValue < other.fixedPointValue;
}
bool Fixed::operator >=(const Fixed& other) const
{
	return this->fixedPointValue >= other.fixedPointValue;
}
bool Fixed::operator <=(const Fixed& other) const
{
	return this->fixedPointValue <= other.fixedPointValue;
}
bool Fixed::operator ==(const Fixed& other) const
{
	return this->fixedPointValue == other.fixedPointValue;
}
bool Fixed::operator !=(const Fixed& other) const
{
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
