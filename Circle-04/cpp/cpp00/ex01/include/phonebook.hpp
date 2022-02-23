#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "util.hpp"
#include "context.hpp"
#define MAX_NUMBER 8

class Phonebook {
    private:
    int idx;
    Context contexts[MAX_NUMBER];
    std::string _stringf(std::string);

    public:
    Phonebook();
    ~Phonebook();
    void add();
    void search();
    void detailSearch();
};

Phonebook::Phonebook() : idx(0) {}

Phonebook::~Phonebook() {}

void Phonebook::add() {
    this->contexts[this->idx].initContext(this->idx);
    this->idx = (this->idx + 1) % MAX_NUMBER;
}
void Phonebook::search() {
    prints((std::string[4]){"index", "first_name", "last_name", "nickname"});
    for (int i = 0 ; i < MAX_NUMBER ; i++) {
        std::string temp = static_cast<std::string>(i + 1);
        prints((std::string[4]){
            temp,
            _stringf(contexts[i].getFirstName()),
            _stringf(contexts[i].getLastName()),
            _stringf(contexts[i].getNickName()),
        });
    }
}

void Phonebook::detailSearch() {
    int idx;
    
    std::cout << "\nEnter the index to display the contact information\n" << " -> ";
	while (true)
	{
		std::cin >> idx;
		if (std::cin.fail()) {
			std::cin.clear();\
            std::cin.ignore(32767, '\n');
		    std::cout << "input correct index(1 ~ 8)\n" << " -> ";
        } else if (idx > 0 && idx <= 8){
            std::cin.ignore(32767, '\n');
            break;
        } else {
            std::cin.clear();
            std::cout << "input correct index(1 ~ 8)\n" << " -> ";
        }
	}
    contexts[idx - 1].printDetail();
}

std::string Phonebook::_stringf(std::string str) {
    if (str.length() > 10)
        return str.substr(0,9) + ".";
    return str;
}

#endif