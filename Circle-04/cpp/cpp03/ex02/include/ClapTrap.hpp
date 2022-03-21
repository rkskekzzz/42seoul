#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    protected:
		std::string name;
		unsigned int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;
    public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap&);

		ClapTrap& operator=(const ClapTrap&);

		void attack(std::string const& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		unsigned int getAttackDamage();
};


#endif

