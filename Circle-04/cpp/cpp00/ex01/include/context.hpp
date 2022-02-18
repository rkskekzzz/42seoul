#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <iomanip>
#include <iostream>
class Context {
    private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    public:
    void initContext();
    void printContext();
};

void Context::initContext() {
    std::string input;

    std::cout << "first_name : ";
    std::getline(std::cin, input);
    this->first_name = input;
    
    std::cout << "last_name : ";
    std::getline(std::cin, input);
    this->last_name = input;
    
    std::cout << "nickname : ";
    std::getline(std::cin, input);
    this->nickname = input;

    std::cout << "phone_number : ";
    std::getline(std::cin, input);
    this->phone_number = input;

    std::cout << "darkest_secret : ";
    std::getline(std::cin, input);
    this->darkest_secret = input;
}

void Context::printContext() {
    std::cout << this->first_name << std::endl;
    std::cout << this->last_name << std::endl;
    std::cout << this->nickname << std::endl;
    std::cout << this->phone_number << std::endl;
    std::cout << this->darkest_secret << std::endl;
}

#endif