#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "[WrongCat] Constructor called!" << std::endl;
}
WrongCat::WrongCat(const WrongCat& origin) {
	std::cout << "[WrongCat] Constructor called!(copied)" << std::endl;
	*this = origin;
}
WrongCat::~WrongCat() {
	std::cout << "[WrongCat] Destructor called!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rvalue) {
	this->type = rvalue.type;
	return *this;
}
