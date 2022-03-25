#include "CastClass.hpp"

CastClass::CastClass(std::string value) {
	this->value = castToDouble(value);
}

CastClass::~CastClass() {}

double CastClass::castToDouble(std::string value) const {
	return std::stod(value);
}

char CastClass::castToChar() const {
	char ch;
	if (isnan(this->value) || isinf(this->value))
		throw Imposible();
	ch = static_cast<char>(this->value);
	if (!isprint(ch))
		throw NonDisplayable();
	return ch;
}
int CastClass::castToInt() const {
	int in;
	if (isnan(this->value) || isinf(this->value))
		throw Imposible();
	in = static_cast<int>(this->value);
	return in;
}
float CastClass::castToFloat() const {
	float fl;
	fl = static_cast<double>(this->value);
	return fl;
}


void CastClass::printCharValue() const{
	std::cout << "Char: ";
	try {
		std::string cast = "";
		cast += this->castToChar();
		std::cout << "\'" << cast << "\'" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;;
	}
}
void CastClass::printIntValue() const {
	std::cout << "Int: ";
	try {
		std::cout << castToInt() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;;
	}
}
void CastClass::printDoubleValue() const {
	std::cout << "Double: ";
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << this->value << std::endl;
}
void CastClass::printFloatValue() const {
	int i = static_cast<int>(value);
	std::cout << "Float: ";
	std::cout << this->value;
	if (i - value == 0)
    	std::cout << ".0f" << std::endl;
	else
    	std::cout << "f" << std::endl;
}

const char * CastClass::Imposible::what() const throw() {
	return "Imposible";
}

const char * CastClass::NonDisplayable::what() const throw() {
	return "Non displayable";
}
