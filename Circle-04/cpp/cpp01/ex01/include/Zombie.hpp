#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <sstream>
#include <iostream>
#include <string>

class Zombie {
    private:
        std::string _name;
    
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce();
        void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);
void randomChump(std::string name);

#endif