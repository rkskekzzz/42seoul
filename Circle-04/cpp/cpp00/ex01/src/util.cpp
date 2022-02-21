#include "util.hpp"

void prints(std::string str[]) {
    std::cout << "|" << std::setw(10) << str[0] \
              << "|" << std::setw(10) << str[1] \
              << "|" << std::setw(10) << str[2] \
              << "|" << std::setw(10) << str[3] \
              << "|" << std::endl;
    
}