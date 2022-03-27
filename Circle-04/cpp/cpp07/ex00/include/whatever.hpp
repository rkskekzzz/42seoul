#include <iostream>

template <typename T>
void swap(T& a, T& b) {
	T tmp;

	tmp = b;
	b = a;
	a = tmp;
}

template <typename T>
T min(T const& a, T const& b) {
	return a < b ? a : b;
}

template <typename T>
T max(T const& a, T const& b) {
	return a < b ? b : a;
}
