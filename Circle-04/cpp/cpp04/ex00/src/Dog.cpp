#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout << "[Dog] Constructor called!" << std::endl;
}

Dog::~Dog() {
	std::cout << "[Dog] Destructor called!" << std::endl;
}

Dog::Dog(const Dog& origin) {
	std::cout << "[Dog] Constructor called!(copied)" << std::endl;
	*this = origin;
}

Dog& Dog::operator=(const Dog& rvalue) {
	this->type = rvalue.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "멍멍!" << std::endl;
}
