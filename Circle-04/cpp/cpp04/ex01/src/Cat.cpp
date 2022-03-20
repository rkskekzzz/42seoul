#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {}


Cat::~Cat() {}

Cat::Cat(const Cat& origin) {
	*this = origin;
}

Cat& Cat::operator=(const Cat& rvalue) {
	this->type = rvalue.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "냐옹~" << std::endl;
}
