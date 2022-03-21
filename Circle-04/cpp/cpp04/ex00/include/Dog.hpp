#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"

class Dog : public Animal {
    private:
    public:
		Dog();
		Dog(const Dog&);
		~Dog();

		Dog& operator=(const Dog&);

		void makeSound() const;
};


#endif

