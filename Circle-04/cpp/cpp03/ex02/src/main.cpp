#include <string>

#include "FragTrap.hpp"

int main() {
    FragTrap a("a");
    FragTrap b("b");

    a.attack("b");
    b.takeDamage(a.getAttackDamage());

    b.beRepaired(10);
    a.highFivesGuys();
}
