#include "ClapTrap.hpp"

int main() {
	ClapTrap one("one");
	ClapTrap two("two");

	one.attack("two");
	two.takeDamage(5);
	two.attack("one");
	one.takeDamage(5);
	one.beRepaired(5);

	one.attack("two");
	two.takeDamage(5);

	return 0;
}
