#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << this->name << " is generated !" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " is Destroy !" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << name << " is generated !" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& origin) {
	std::cout << "ScavTrap " << name << " is generated(copied) !" << std::endl;
	*this = origin;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rvalue) {
	this->name = rvalue.name;
	this->hit_points = rvalue.hit_points;
	this->energy_points = rvalue.energy_points;
	this->attack_damage = rvalue.attack_damage;
	return *this;
}

void ScavTrap::attack(std::string const& target) {
	std::cout << "ScavTrap " << this->name << " attack " << target << " causing " << this->attack_damage << " points of damage !" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " enterred in Gate keeper mode. " << std::endl;
}
