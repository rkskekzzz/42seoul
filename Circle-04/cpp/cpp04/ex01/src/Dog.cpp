#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {}

Dog::~Dog() {}

Dog::Dog(const Dog& origin) {
	*this = origin;
}

Dog& Dog::operator=(const Dog& rvalue) {
	this->type = rvalue.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "멍멍!" << std::endl;
}
