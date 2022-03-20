#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();
    const Animal* animals[10];

    for (int i = 0 ; i < 10 ; i++) {
        if (i % 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0 ; i < 10 ; i++)
        animals[i]->makeSound();

    const Animal* copy = new Animal(*dog);


	delete dog;
    delete cat;
    delete copy;
}
