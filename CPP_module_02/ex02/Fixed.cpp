#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _raw(0)
{
}

Fixed::Fixed(const int value)
{
    _raw = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    _raw = (int)roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) 
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        _raw = other._raw;
    return *this;
}

Fixed::~Fixed()
{
}

float Fixed::toFloat(void) const
{
    return (float)_raw / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _raw >> _fractionalBits;
}

int Fixed::getRawBits(void) const
{
    return _raw;
}

void Fixed::setRawBits(int const raw)
{
    _raw = raw;
}

bool Fixed::operator>(const Fixed& other) const 
{ 
    return _raw > other._raw; 
}

bool Fixed::operator<(const Fixed& other) const 
{ 
    return _raw < other._raw; 
}
bool Fixed::operator>=(const Fixed& other) const 
{ 
    return _raw >= other._raw; 
}
bool Fixed::operator<=(const Fixed& other) const 
{ 
    return _raw <= other._raw; 
}
bool Fixed::operator==(const Fixed& other) const 
{ 
    return _raw == other._raw; 
}
bool Fixed::operator!=(const Fixed& other) const 
{ 
    return _raw != other._raw; 
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed r;
    r.setRawBits(this->_raw + other._raw);
    return r;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed r;
    r.setRawBits(this->_raw - other._raw);
    return r;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed r;
    long tmp = (long)this->_raw * (long)other._raw;
    r.setRawBits((int)(tmp >> _fractionalBits));
    return r;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed r;
    long tmp = ((long)this->_raw << _fractionalBits); 
    r.setRawBits((int)(tmp / other._raw));            
    return r;
}

Fixed& Fixed::operator++()
{
    _raw += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed before(*this);
    _raw += 1;
    return before;
}

Fixed& Fixed::operator--()
{
    _raw -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed before(*this);
    _raw -= 1;
    return before;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}