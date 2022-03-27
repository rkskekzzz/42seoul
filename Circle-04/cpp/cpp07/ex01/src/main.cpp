#include "iter.hpp"


template <typename T>
void print(T const& t) {
	std::cout << t << std::endl;
}

int main(void) {
	int array_int[7] = [0, 1, 2, 3, 4, 5, 6, 7];
	std::string array_str[7] = ["mon", "tue", "wed", "thr", "fri", "sat", "sun"];

	iter(&array_int, 7, print);
	iter(&array_str, 7, print);
}
