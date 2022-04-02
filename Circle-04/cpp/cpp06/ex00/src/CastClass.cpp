#include "CastClass.hpp"

CastClass::CastClass(std::string value) {
	this->value = castToDouble(value);
}

CastClass::~CastClass() {}

bool CastClass::regexValue(std::string value) {
	bool has_dot = false;
	unsigned int idx = 0;
	if (value[idx] == '+' || value[idx] == '-')
		++idx;
	if (!std::isdigit(value[idx]))
		return false;
	while (idx < value.length()) {
		if (value[idx] == '.') {
			if (has_dot)
				return false;
			has_dot = true;
			if (idx + 1 == value.length())
				return true;
			if (!isdigit(value[idx + 1]))
				return false;
			++idx;
		}
		if (value[idx] == 'f' && idx == value.length() - 1)
			return true;
		if (value[idx] == 'f' && idx != value.length() - 1)
			return false;
		if (!std::isdigit(value[idx]))
			return false;
		++idx;
	}
	while (++idx < value.length()) {
		if (value[idx] == 'f')
			break;
		if (std::isdigit(value[idx]))
			return false;
	}
	return true;
}

double CastClass::castToDouble(std::string value) {
	double dub = 0;

	dub = std::strtod(value.c_str(), NULL);
	if (value == "nan" || value == "nanf")
		this->type = NaN;
	else if (value == "inf" || value == "-inf" || value == "inff" || value == "-inff" || value == "+inf" || value == "+inff")
		this->type = Inf;
	else if (!regexValue(value))
		this->type = CantCasting;
	else if (value.length() == 1 && value[0] > 32 && value[0] < 127)
		this->type = Char;
	else
		this->type = Number;
	return dub;
}

char CastClass::castToChar()  {
	char ch;
	if (this->type != Number && this->type != Char)
		throw Imposible();
	ch = static_cast<char>(this->value);
	if (!std::isprint(ch))
		throw NonDisplayable();
	return ch;
}
int CastClass::castToInt() {
	int in;
	if (this->type != Number && this->type != Char)
		throw Imposible();
	in = static_cast<int>(this->value);
	return in;
}
float CastClass::castToFloat() {
	float fl;
	fl = static_cast<double>(this->value);
	return fl;
}

CastClass::InputType CastClass::getType() {
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
	int i = static_cast<int>(value);
	std::cout << "Double: ";
	if (i - value == 0) {
		std::cout << std::fixed;
		std::cout.precision(1);
	} else {
		std::cout.precision();
	}
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
