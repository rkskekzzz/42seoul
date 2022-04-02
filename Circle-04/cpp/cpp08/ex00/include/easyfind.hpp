#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define DEFAULT "\033[39m"

class NotFoundException : public std::exception {
public:
	const char *what() const throw() {
		return "Value not found";
	}
};

template<typename T>
bool easyfind(T& t, int i) {
	std::cout << "find : " << i << std::endl;

	if (std::find(t.begin(), t.end(), i) == t.end())
		throw NotFoundException();
	std::cout << GREEN << "Value found!" << DEFAULT << std::endl;
	return true;
}

#endif
