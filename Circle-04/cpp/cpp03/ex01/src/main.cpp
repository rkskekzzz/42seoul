#include <string>

#include "ScavTrap.hpp"

int main() {
    ScavTrap one("one");
    ScavTrap two("two");
    ScavTrap three;

    three = one;

	one.attack("two");
    two.takeDamage(0);

    two.beRepaired(10);
    one.guardGate();
}
