#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"

class Dog : public Animal {
    private:
    public:
		Dog();
		Dog(const Dog&);
		virtual ~Dog();

		Dog& operator=(const Dog&);

		virtual void makeSound() const;
};


#endif

