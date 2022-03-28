#include "CastClass.hpp"

CastClass::CastClass(std::string value) {
	this->value = castToDouble(value);
}

CastClass::~CastClass() {}

double CastClass::castToDouble(std::string value) {
	double dub = 0;
	try {
		dub = std::stod(value.c_str(), NULL);
	} catch (std::exception &e) {
		std::cout << value.length() << std::endl;
		if (value.length() != 1) {
			this->type = CantCasting;
			return dub;
		}
		dub = value[0];
	}
	if (value == "nan" || value == "nanf")
		this->type = NaN;
	else if (value == "inf" || value == "-inf" || value == "inff" || value == "-inff")
		this->type = Inf;
	else
		this->type = Number;
	return dub;
}

char CastClass::castToChar()  {
	char ch;
	if (this->type != Number)
		throw Imposible();
	ch = static_cast<char>(this->value);
	if (!std::isprint(ch))
		throw NonDisplayable();
	return ch;
}
int CastClass::castToInt() {
	int in;
	if (this->type != Number)
		throw Imposible();
	in = static_cast<int>(this->value);
	return in;
}
float CastClass::castToFloat() {
	float fl;
	fl = static_cast<double>(this->value);
	return fl;
}

InputType CastClass::getType() {
	return this->type;
}


void CastClass::printCharValue(){
	std::cout << "Char: ";
	try {
		std::string cast = "";
		cast += this->castToChar();
		std::cout << "\'" << cast << "\'" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;;
	}
}
void CastClass::printIntValue() {
	std::cout << "Int: ";
	try {
		std::cout << castToInt() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;;
	}
}
void CastClass::printDoubleValue() {
	std::cout << "Double: ";
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << this->value << std::endl;
}
void CastClass::printFloatValue() {
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
