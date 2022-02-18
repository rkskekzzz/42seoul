#include <iostream>
#include "phonebook.hpp"

int main() {
    Phonebook phonebook;
    std::string cmd;

    for(;;) {
        std::cout << "*** Input Your Command**\n";
        std::getline(std::cin, cmd);
        if (cmd == "EXIT") {
            break ;
        } else if (cmd == "ADD" || cmd == "add" ) {
            phonebook.add();
        } else if (cmd == "SEARCH" || cmd == "search") {
            phonebook.search();
        } else {
            std::cout << "cmd error\n";
        }
    }
    return (0);
}