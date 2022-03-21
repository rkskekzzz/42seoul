#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : \
	name("noname"), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap " << name << " is generated !" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " is Destroy !" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : \
	name(name), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap " << name << " is generated !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& origin) {
	std::cout << "ClapTrap " << name << " is generated(copied) !" << std::endl;
	*this = origin;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rvalue) {
	this->name = rvalue.name;
	this->hit_points = rvalue.hit_points;
	this->energy_points = rvalue.energy_points;
	this->attack_damage = rvalue.attack_damage;
	return *this;
}

void ClapTrap::attack(std::string const& target) {
	std::cout << "ClapTrap " << this->name << " attack " << target << "!!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->name << " take " << amount  << " points of damage !" << std::endl;
	if (amount > this->hit_points) {
		this->hit_points = 0;
	} else {
		this->hit_points -= amount;
	}
	std::cout << "..." << this->name << " : " << this->hit_points << " hp is remained" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (amount > this->energy_points) {
		std::cout << "...ClapTrap " << this->name << " not enough " << amount  << " points !(remain : " << this->energy_points<< ")" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " be Repaired " << amount  << " points of energy_points !" << std::endl;
	this->hit_points += amount;
	std::cout << "..." << this->name << " : " << this->hit_points << " hp is remained" << std::endl;
}

unsigned int ClapTrap::getAttackDamage() {
	return this->attack_damage;
}
