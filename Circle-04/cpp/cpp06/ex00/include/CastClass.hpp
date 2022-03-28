#ifndef CASTCLASS_HPP
#define CASTCLASS_HPP

#include <string>
#include <exception>
#include <iostream>
#include <iomanip>

enum InputType {
	Number = 0,
	NaN,
	Inf,
	CantCasting
};
class CastClass {
	private:
		double value;
		InputType type;
	public:
		CastClass(std::string value);
		~CastClass();

		char castToChar();
		int castToInt();
		float castToFloat();
		double castToDouble(std::string value);

		InputType getType();

		void printCharValue();
		void printIntValue();
		void printDoubleValue();
		void printFloatValue();

		class Imposible : public std::exception {
			const char * what() const throw();
		};
		class NonDisplayable : public std::exception {
			const char * what() const throw();
		};
};

#endif
