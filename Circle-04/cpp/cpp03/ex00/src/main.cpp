#include "ClapTrap.hpp"

int main() {
	ClapTrap one("one");
	ClapTrap two("two");

	one.attack("two");
	two.takeDamage(5);
	one.takeDamage(5);
	one.beRepaired(5);

	two.takeDamage(5);

	return 0;
}
