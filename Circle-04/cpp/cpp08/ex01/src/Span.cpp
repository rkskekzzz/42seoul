#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int maxSize) : _maxSize(maxSize) {}

Span::~Span() {}

Span::Span(Span const& origin) {
	*this = origin;
}

Span& Span::operator=(Span const& rvalue) {
	_vector.clear();
	_maxSize = rvalue._maxSize;

	for (unsigned int i = 0; i < _maxSize; i++)
		_vector.push_back(rvalue._vector[i]);

	return *this;
}

void Span::addNumber(int value) {
	if (_vector.size() == _maxSize)
		throw SpanSizeIsMaximum();
	if (std::find(_vector.begin(), _vector.end(), value) != _vector.end())
		throw AlreadyContainNumber();
	_vector.push_back(value);
}

int Span::shortestSpan() {
	if (_vector.size() <= 1)
		throw NotEnoughItems();
	std::vector<int> sorted = _vector;
	std::sort(sorted.begin(), sorted.end());
	int shortest = __INT_MAX__;

	for (std::vector<int>::iterator iter = sorted.begin() + 1; iter != sorted.end(); iter++) {
		shortest = std::min(shortest, std::abs(*iter - *(iter - 1)));
	}
	return shortest;
}

int Span::longestSpan() {
	if (_vector.size() <= 1)
		throw NotEnoughItems();
	int longest = *std::max_element(_vector.begin(), _vector.end()) - *std::min_element(_vector.begin(), _vector.end());

	return longest;
}

const char * Span::AlreadyContainNumber::what() const throw() {
	return "Already Contain Number!";
}

const char * Span::SpanSizeIsMaximum::what() const throw() {
	return "Span Size Is Maximum!";
}

const char * Span::NotEnoughItems::what() const throw() {
	return "Not Enough Items!";
}
