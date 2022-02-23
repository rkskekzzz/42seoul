#include "Zombie.hpp"

void Zombie::announce() {
    std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name) {
    this->_name = name;
}

Zombie::Zombie() : _name("noname") {}
Zombie::Zombie(std::string name) : _name(name) {}
Zombie::~Zombie() {
    std::cout << "<" << this->_name << "> Die~! " << std::endl;
}