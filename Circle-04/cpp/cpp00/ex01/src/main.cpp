#include <iostream>
#include "phonebook.hpp"

int main() {
    Phonebook phonebook;
    std::string cmd;

    for(;;) {
        std::cout << "*** Input Your Command**\n" << " >> ";
        std::getline(std::cin, cmd);
        if (cmd == "EXIT" || cmd == "exit") {
            break ;
        } else if (cmd == "ADD" || cmd == "add" ) {
            phonebook.add();
        } else if (cmd == "SEARCH" || cmd == "search") {
            phonebook.search();
            phonebook.detailSearch();
        } else {
            std::cout << "cmd error\n";
        }
        std::cout << std::endl;
    }
    return (0);
}