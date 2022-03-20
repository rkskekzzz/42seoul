#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("notype") {
	std::cout << "[WrongAnimal] Constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : type(name) {
	std::cout << "[WrongAnimal] Constructor called! : " << name << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "[WrongAnimal] Destructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& origin) {
	std::cout << "[WrongAnimal] Constructor called!(copied)" << std::endl;
	*this = origin;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rvalue) {
	this->type = rvalue.type;
	return *this;
}

std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {
	std::cout << "...wrong wrong" << std::endl;
}
