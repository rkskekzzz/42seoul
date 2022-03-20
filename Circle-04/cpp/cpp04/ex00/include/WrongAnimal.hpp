#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal{
    protected:
		std::string type;
    public:
		WrongAnimal();
		WrongAnimal(std::string name);
		WrongAnimal(const WrongAnimal&);
		virtual ~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal&);

		std::string getType() const;
		void makeSound() const;
};


#endif

