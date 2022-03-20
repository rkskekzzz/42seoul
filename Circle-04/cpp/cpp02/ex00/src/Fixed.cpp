#include "Fixed.hpp"
#include <iostream>

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

Fixed& Fixed::operator=(const Fixed& rvalue) {
    std::cout << "Assignation operator called" << std::endl;
    this->setRawBits(rvalue.getRawBits());
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_pointer;
}

void Fixed::setRawBits(int const raw) {
    this->fixed_pointer = raw;
}

