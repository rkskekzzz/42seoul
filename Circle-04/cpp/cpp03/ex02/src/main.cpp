#include <string>

#include "FragTrap.hpp"

int main() {
    FragTrap a("a");
    FragTrap b("b");

    a.attack("b");
    b.takeDamage(0);

    b.beRepaired(10);
    a.highFivesGuys();
}
