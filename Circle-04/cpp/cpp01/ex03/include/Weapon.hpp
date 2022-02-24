#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>

class Weapon {
    private:
        std::string _type;

    public:
        const std::string &getType();
        void setType(std::string type);
};

#endif
