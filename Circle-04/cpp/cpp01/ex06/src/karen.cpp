#include "Karen.hpp"
#include <iostream>

Karen::Karen() {}

Karen::~Karen() {}

void Karen::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.I just love it!" << std::endl;
}

void Karen::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money.You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain(std::string complain) {
    std::string array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Karen::*f[4])() = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};

    int index;
    for (index = 0; index < 4 ; index++)
        if (array[index] == complain) break;


    switch (index) {
    case 0:
        (this->*f[index])();
        break;
    case 1:
        (this->*f[index])();
        break;
    case 2:
        (this->*f[index])();
        break;
    case 3:
        (this->*f[index])();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}
