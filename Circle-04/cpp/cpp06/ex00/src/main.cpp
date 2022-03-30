#include "CastClass.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		return 1;
	CastClass cast(argv[1]);
	if (cast.getType() == CastClass::CantCasting) {
		std::cout << "Can't Casting" << std::endl;
		return 1;
	}
	cast.printCharValue();
	cast.printIntValue();
	cast.printFloatValue();
	cast.printDoubleValue();
	return 0;
}
