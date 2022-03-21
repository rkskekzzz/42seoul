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
	this->brain = new Brain(*origin.brain);
	this->type = origin.type;
	std::cout << "[Cat] Constructor called!(copied)" << std::endl;
}

Cat& Cat::operator=(const Cat& rvalue) {
	if (this != &rvalue) {
		delete this->brain;
		this->brain = new Brain(*rvalue.brain);
		this->type = rvalue.type;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "냐옹~!" << std::endl;
}
