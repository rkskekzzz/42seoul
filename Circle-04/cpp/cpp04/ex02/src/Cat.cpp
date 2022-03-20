#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	this->brain = new Brain();
	std::cout << "[Cat] Constructor called!" << std::endl;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "[Cat] Destructor called!" << std::endl;
}

Cat::Cat(const Cat& origin) {
	this->type = origin.type;
	this->brain = new Brain();
	this->brain = origin.brain;
	std::cout << "[Cat] Constructor called!(copied)" << std::endl;
}

Cat& Cat::operator=(const Cat& rvalue) {
	this->brain = rvalue.brain;
	this->type = rvalue.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "냐옹~" << std::endl;
}
