#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[Brain] Constructor called!" << std::endl;
}

Brain::Brain(std::string ideas[100]) {
	for (int i = 0 ; i < 100 ; i++) {
		this->ideas[i] = ideas[i];
	}
	std::cout << "[Brain] Constructor called!" << std::endl;
}

Brain::Brain(const Brain& origin) {
	*this = origin;
	std::cout << "[Brain] Constructor called!(copied)" << std::endl;
}

Brain::~Brain() {
	std::cout << "[Brain] Destructor called!" << std::endl;
}

Brain& Brain::operator=(const Brain& rvalue) {
	for (int i = 0 ; i < 100 ; i++) {
		this->ideas[i] = rvalue.ideas[i];
	}
	return *this;
}
