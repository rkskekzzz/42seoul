#include "easyfind.hpp"

int main(void) {

	std::vector<int> vt;
	vt.push_back(10);
	vt.push_back(20);
	vt.push_back(30);
	vt.push_back(40);
	try {
		easyfind(vt, 42);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		easyfind(vt, 30);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
