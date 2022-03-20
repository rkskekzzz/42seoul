#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Cat* cat = new Cat();
    const Dog* dog = new Dog();
    // const Animal* animal = new Animal();

    cat->makeSound();
    dog->makeSound();

	delete dog;
    delete cat;
}
