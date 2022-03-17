#include "../include/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixed_pointer(0) {
    std::cout << "Default Constructor called" << std::endl;
};

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& origin) {
    std::cout << "Copy constructor called" << std::endl;
    *this = origin;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(value << this->fractional_bit);
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->setRawBits((int)roundf(value * (1 << this->fractional_bit)));
}

Fixed& Fixed::operator=(const Fixed& rvalue) {
    std::cout << "Assignation operator called" << std::endl;
    this->setRawBits(rvalue.getRawBits());
    return *this;
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
