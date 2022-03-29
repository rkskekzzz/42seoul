#include "Array.hpp"

int main(void) {
	Array<int> a;
	Array<int> b(4);
	Array<int> c(2);
	Array<int> d(c);
	c[0] = 10;
	std::cout << "a:" << a << std::endl;
	std::cout << "b:" << b << std::endl;
	std::cout << "c:" <<c << std::endl;
	c = b;
	b[2] = 5;
	try {
		b[6] = 0;
	} catch(std::exception e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "b:" << b << std::endl;
	std::cout << "c:" <<c << std::endl;
	std::cout << "d:" <<d << std::endl;
}
