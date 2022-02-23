#include "Zombie.hpp"

int main() {
    int countOfZombies = 10;
    Zombie *zombies;
    zombies = zombieHorde(countOfZombies, "ZZZZ");


    for (int i = 0 ; i < countOfZombies ; i++) {
        zombies[i].announce();
    }
    

    delete[] zombies;

    return (0);
}