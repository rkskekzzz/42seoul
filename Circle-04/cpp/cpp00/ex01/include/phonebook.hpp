#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <iostream>
#include "context.hpp"
#define MAX_NUMBER 8

class Phonebook {
    private:
    int idx;
    Context contexts[MAX_NUMBER];

    public:
    Phonebook();
    ~Phonebook();
    
    void add();
    void search();
};

Phonebook::Phonebook() : idx(0) {}

Phonebook::~Phonebook() {}

void Phonebook::add() {
    this->idx = (this->idx + 1) % MAX_NUMBER;
    this->contexts[this->idx].initContext();
}
void Phonebook::search() {
    std::cout << "hi\n";
}

#endif