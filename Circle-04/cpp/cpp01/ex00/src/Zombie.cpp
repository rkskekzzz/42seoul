#include "Zombie.hpp"

void Zombie::announce() {
    std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ...\n";
}
Zombie::Zombie() : _name("noname") {}
Zombie::Zombie(std::string name) : _name(name) {}
Zombie::~Zombie() {
    std::cout << "<" << this->_name << "> Die~! " << std::endl;
}