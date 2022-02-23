#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) {
    this->_name = name;
    this->_weapon = weapon;
}

void attack() {
    std::cout << this->_name << " attacks with his " << this->getType() << std::endl;
}