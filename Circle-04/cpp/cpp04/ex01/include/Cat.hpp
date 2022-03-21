#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* brain;
    public:
		Cat();
		Cat(const Cat&);
		~Cat();

		Cat& operator=(const Cat&);

		void makeSound() const;
};


#endif

