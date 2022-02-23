#include <string>
#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";

    std::string *strPTR = &str;
    std::string &strREF = str;

    std::cout << "strPTR : " << *strPTR << std::endl;
    std::cout << "strREF : " << strREF << std::endl;
    return (0);
}