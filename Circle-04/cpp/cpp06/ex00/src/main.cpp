#include "CastClass.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		return 1;
	try {
		CastClass cast(argv[1]);
		cast.printCharValue();
		cast.printIntValue();
		cast.printFloatValue();
		cast.printDoubleValue();
	} catch (std::exception &e) {
		std::cout << "Can't Casting!" << std::endl;
		return 1;
	}
	return 0;
}
