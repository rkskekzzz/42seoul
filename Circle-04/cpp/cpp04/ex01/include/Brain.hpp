#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain{
    protected:
		std::string ideas[100];
    public:
		Brain();
		Brain(const Brain&);
		virtual ~Brain();

		Brain& operator=(const Brain&);

		std::string getType() const;
		virtual void makeSound() const;
};


#endif

