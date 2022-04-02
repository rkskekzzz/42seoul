#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define DEFAULT "\033[39m"

class Span {
public:
	class AlreadyContainNumber : public std::exception {
		const char * what() const throw();
	};
	class SpanSizeIsMaximum : public std::exception {
		const char * what() const throw();
	};
	class NotEnoughItems : public std::exception {
		const char * what() const throw();
	};

	Span();
	Span(unsigned int);
	~Span();
	Span(Span const&);
	Span& operator=(Span const&);

	void addNumber(int value);
	template<template <class T, class Allocator = std::allocator<T> > class Container>
	void addNumber(Container<int> c);
	int shortestSpan();
	int longestSpan();


private:
	std::vector<int> _vector;
	unsigned int _maxSize;
};

template<template <class T, class Allocator = std::allocator<T> > class Container>
void Span::addNumber(Container<int> c) {

	for (typename Container<int>::iterator iter = c.begin() ; iter != c.end() ; iter++) {
		addNumber(*iter);
	}
}

#endif
