#include "Span.hpp"

int main() {
	Span sp = Span(9);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::vector<int> vec;
		// vec.push_back(11);
		vec.push_back(12);
		vec.push_back(13);
		vec.push_back(14);
		sp.addNumber(vec);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
