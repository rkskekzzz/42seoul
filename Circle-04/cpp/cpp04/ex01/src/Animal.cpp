#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("notype") {}

Animal::Animal(std::string name) : type(name) {}

Animal::~Animal() {}

Animal::Animal(const Animal& origin) {
	*this = origin;
}

Animal& Animal::operator=(const Animal& rvalue) {
	this->type = rvalue.type;
	return *this;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "..." << std::endl;
}
