#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	this->brain = new Brain();
	std::cout << "[Dog] Constructor called!" << std::endl;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "[Dog] Destructor called!" << std::endl;
}

Dog::Dog(const Dog& origin) {
	this->type = origin.type;
	this->brain = new Brain();
	this->brain = origin.brain;
	std::cout << "[Dog] Constructor called!(copied)" << std::endl;
}

Dog& Dog::operator=(const Dog& rvalue) {
	this->brain = rvalue.brain;
	this->type = rvalue.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "멍멍!" << std::endl;
}
