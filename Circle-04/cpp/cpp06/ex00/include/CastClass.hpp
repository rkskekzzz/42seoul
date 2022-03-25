#ifndef CASTCLASS_HPP
#define CASTCLASS_HPP

#include <string>
#include <exception>
#include <iostream>
#include <ctype.h>
#include <float.h>
#include <math.h>
#include <iomanip>

class CastClass {
	private:
		double value;
	public:
		CastClass(std::string value);
		~CastClass();

		char castToChar() const;
		int castToInt() const;
		float castToFloat() const;
		double castToDouble(std::string value) const;


		void printCharValue() const;
		void printIntValue() const;
		void printDoubleValue() const;
		void printFloatValue() const;

		class Imposible : public std::exception {
			const char * what() const throw();
		};
		class NonDisplayable : public std::exception {
			const char * what() const throw();
		};
};

#endif
