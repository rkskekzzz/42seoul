#include <iostream>
#include <random>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
 	srand((unsigned int)time(NULL));
	int i = rand() % 3;
	switch(i)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void	identify(Base* p)
{
	std::cout << "<Pointer>" << std::endl;

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	std::cout << "<Reference>" << std::endl;

	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception & e) {
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception & e) {
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception & e){
		std::cout << "no match type!" << std::endl;
	}}}
}
int main() {
	Base * test = generate();

	identify(test);
	identify(*test);
}
