#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    protected:
		std::string name;
		int hit_points;
		int energy_points;
		int attack_damage;
    public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap&);

		ClapTrap& operator=(const ClapTrap&);

		void attack(std::string const& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		int getAttackDamage() const;
		int getHitPoints() const;
		int getEnergyPoints() const;
};


#endif

