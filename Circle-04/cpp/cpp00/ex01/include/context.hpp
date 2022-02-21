#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <iomanip>
#include <iostream>
class Context {
    private:
    int idx;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    public:
    void initContext(int idx);
    void printDetail();
    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getPhoneNumber();
    std::string getDarkestSecret();
};

std::string Context::getFirstName() {
    return this->first_name;
}

std::string Context::getLastName() {
    return this->last_name;
}
std::string Context::getNickName() {
    return this->nickname;
}
std::string Context::getPhoneNumber() {
    return this->phone_number;
}
std::string Context::getDarkestSecret() {
    return this->darkest_secret;
}

void Context::printDetail() {
    std::cout << "first_name : " << this->first_name << std::endl;
    std::cout << "last_name : " << this->last_name << std::endl;
    std::cout << "nickname : " << this->nickname << std::endl;
    std::cout << "phone_number : " << this->phone_number << std::endl;
    std::cout << "darkest_secret : " << this->darkest_secret << std::endl;
}

void Context::initContext(int idx) {
    std::string input;

    this->idx = idx;

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

#endif