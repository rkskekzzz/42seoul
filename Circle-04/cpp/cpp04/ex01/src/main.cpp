#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();
    const Animal* copy = new Animal(*dog);

    std::cout << copy->getType() << std::endl;

	delete dog;
    delete cat;
    delete copy;
}
