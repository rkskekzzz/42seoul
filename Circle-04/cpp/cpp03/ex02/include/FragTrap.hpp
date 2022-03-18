#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
    private:
    public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap&);

		FragTrap& operator=(const FragTrap&);

		void attack(std::string const& target);

		void highFivesGuys(void);
};


#endif

