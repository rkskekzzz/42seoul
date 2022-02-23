#include "Zombie.hpp"

int main() {
    Zombie zombie0("suhshin");
    Zombie *zombie1;

    zombie1 = newZombie("ycha");
    zombie1->announce();

    randomChump("hyson");

    delete zombie1;

    return (0);
}