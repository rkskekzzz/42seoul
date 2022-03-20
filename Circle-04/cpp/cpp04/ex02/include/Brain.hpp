#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>
class Brain{
    protected:
		std::string ideas[100];
    public:
		Brain();
		Brain(std::string ideas[100]);
		Brain(const Brain&);
		~Brain();

		Brain& operator=(const Brain&);
};


#endif

