#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* animals[10];

    for (int i = 0 ; i < 10 ; i++) {
        if (i % 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0 ; i < 10 ; i++)
        animals[i]->makeSound();


    Dog dog1;
    Dog dog2;
    Dog dog3(dog1);

    dog2 = dog1;
}
