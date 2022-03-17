#include "Karen.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "How to Use : ./karen {option}\n option : [DEBUG, INFO, WARNING, ERROR or Sometext]" << std::endl;
        return 1;
    }

	Karen karen;

    karen.complain(argv[1]);
    return 0;
}
