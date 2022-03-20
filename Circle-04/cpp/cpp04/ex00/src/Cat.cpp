#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << "[Cat] Constructor called!" << std::endl;
}


Cat::~Cat() {
	std::cout << "[Cat] Destructor called!" << std::endl;
}

Cat::Cat(const Cat& origin) {
	std::cout << "[Cat] Constructor called!(copied)" << std::endl;
	*this = origin;
}

Cat& Cat::operator=(const Cat& rvalue) {
	this->type = rvalue.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "냐옹~" << std::endl;
}
