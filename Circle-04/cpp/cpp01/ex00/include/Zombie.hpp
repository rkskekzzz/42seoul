#include <iostream>
#include <string>

class Zombie {
    private:
        std::string _name;
    
    public:
        Zombie();
        ~Zombie();
        Zombie(std::string name);
        void announce();
};
Zombie::Zombie() : _name("noname") {}
Zombie::Zombie(std::string name) : _name(name) {}
Zombie::~Zombie() {
    std::cout << this->_name << "Die~!" << std::endl;
}
Zombie* newZombie(std::string name);
void randomChump(std::string name);