#include "../include/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixed_pointer(0) {};

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& origin) {
    *this = origin;
}

Fixed::Fixed(const int value) {
    this->setRawBits(value << this->fractional_bit);
}

Fixed::Fixed(const float value) {
    this->setRawBits((int)roundf(value * (1 << this->fractional_bit)));
}

Fixed& Fixed::operator=(const Fixed& rvalue) {
    this->setRawBits(rvalue.getRawBits());
    return *this;
}

Fixed& Fixed::operator++(void) {
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}
Fixed& Fixed::operator--(void) {
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}

const Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++*this;
    return temp;
}
const Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --*this;
    return temp;
}

bool Fixed::operator<(const Fixed& rvalue) const {
    return this->getRawBits() < rvalue.getRawBits();
}
bool Fixed::operator>(const Fixed& rvalue) const {
    return this->getRawBits() > rvalue.getRawBits();
}
bool Fixed::operator<=(const Fixed& rvalue) const {
    return this->getRawBits() <= rvalue.getRawBits();
}
bool Fixed::operator>=(const Fixed& rvalue) const {
    return this->getRawBits() >= rvalue.getRawBits();
}
bool Fixed::operator==(const Fixed& rvalue) const {
    return this->getRawBits() == rvalue.getRawBits();
}
bool Fixed::operator!=(const Fixed& rvalue) const {
    return this->getRawBits() != rvalue.getRawBits();
}

Fixed Fixed::operator+(const Fixed& rvalue) const{
    return Fixed(this->toFloat() + rvalue.toFloat());
}

Fixed Fixed::operator-(const Fixed& rvalue) const{
    return Fixed(this->toFloat() + rvalue.toFloat());
}

Fixed Fixed::operator*(const Fixed& rvalue) const {
    return Fixed(this->toFloat() * rvalue.toFloat());
}

Fixed Fixed::operator/(const Fixed& rvalue) const{
    return Fixed(this->toFloat() / rvalue.toFloat());
}

const Fixed& Fixed::max(const Fixed& value1, const Fixed& value2) {
    return value1.getRawBits() > value2.getRawBits() ? value1 : value2;
}

const Fixed& Fixed::min(const Fixed& value1, const Fixed& value2) {
    return value1.getRawBits() > value2.getRawBits() ? value1 : value2;
}

int Fixed::getRawBits(void) const {
    return this->fixed_pointer;
}

void Fixed::setRawBits(int const raw) {
    this->fixed_pointer = raw;
}

int Fixed::toInt() const {
    return this->getRawBits() >> this->fractional_bit;
}

float Fixed::toFloat() const {
    return ((float)this->getRawBits() / (float)(1 << this->fractional_bit));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx) {
    os << fx.toFloat();
    return os;
}
