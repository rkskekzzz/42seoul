#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("notype") {
	std::cout << "[Animal] Constructor called!" << std::endl;
}

Animal::Animal(std::string name) : type(name) {
	std::cout << "[Animal] Constructor called! : " << name << std::endl;
}

Animal::~Animal() {
	std::cout << "[Animal] Destructor called!" << std::endl;
}

Animal::Animal(const Animal& origin) {
	std::cout << "[Animal] Constructor called!(copied)" << std::endl;
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
