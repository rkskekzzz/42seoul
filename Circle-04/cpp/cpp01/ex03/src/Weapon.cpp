#include "Weapon.hpp"

std::string Weapon::getWeapon() {
    return this->_type;
}

void Weapon::setWeapon(std::string type) {
    this->_type = type;
}