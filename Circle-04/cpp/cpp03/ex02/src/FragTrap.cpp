#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << this->name << " is generated !" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " is Destroy !" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << name << " is generated !" << std::endl;
}

FragTrap::FragTrap(const FragTrap& origin) {
	std::cout << "FragTrap " << name << " is generated(copied) !" << std::endl;
	*this = origin;
}

FragTrap& FragTrap::operator=(const FragTrap& rvalue) {
	this->name = rvalue.name;
	this->hit_points = rvalue.hit_points;
	this->energy_points = rvalue.energy_points;
	this->attack_damage = rvalue.attack_damage;
	return *this;
}

void FragTrap::attack(std::string const& target) {
	std::cout << "FragTrap " << this->name << " attack " << target << " causing " << this->attack_damage << " points of damage !" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->name << " say < HighFive Guys ! > " << std::endl;
}
