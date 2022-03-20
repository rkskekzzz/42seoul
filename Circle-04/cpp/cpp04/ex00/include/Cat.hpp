#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"

class Cat : public Animal {
    private:
    public:
		Cat();
		Cat(const Cat&);
		virtual ~Cat();

		Cat& operator=(const Cat&);

		virtual void makeSound() const;
};


#endif

