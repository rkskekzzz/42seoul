#include "iter.hpp"

template <typename T>
void print(T const& t) {
	std::string colors[3] = {"\033[31m", "\033[32m" , "\033[34m"};
	std::string colors_default = "\033[39m";

	int i = rand() % 3;

	std::cout << colors[i] << t << colors_default << std::endl;
}

int main(void) {
	int array_int[7] = {0, 1, 2, 3, 4, 5, 6};
	std::string array_str[7] = {"mon", "tue", "wed", "thr", "fri", "sat", "sun"};

	srand((unsigned int)time(NULL));

	iter(array_int, 7, print);
	iter(array_str, 7, print);
}
