#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    private:
    public:
		WrongCat();
		WrongCat(const WrongCat&);
		virtual ~WrongCat();

		WrongCat& operator=(const WrongCat&);
		void makeSound() const;
};


#endif

