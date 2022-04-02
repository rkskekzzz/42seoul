#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack();
	~MutantStack();
	MutantStack(MutantStack const&);
	MutantStack& operator=(MutantStack const&);

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
    iterator end();
private:
};


template<class T>
MutantStack<T>::MutantStack(): std::stack<T>() {}

template<class T>
MutantStack<T>::~MutantStack() {}

template<class T>
MutantStack<T>::MutantStack(MutantStack const& origin) : std::stack<T>(origin) {
}

template<class T>
MutantStack<T>&	MutantStack<T>::operator=(MutantStack<T> const& rvalue) {
	std::stack<T>::operator=(rvalue);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

#endif
