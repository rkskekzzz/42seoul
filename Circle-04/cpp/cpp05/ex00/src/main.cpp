#include <iostream>
#include "Bureaucrat.hpp"
#include "Color.hpp"

void errorCase_decrease() {
	std::cout << BLUE << "ERROR CASE - DECREASE" << DEFAULT << std::endl;
	try {
		Bureaucrat song("song", 100);
		std::cout << song;
		song.decreaseGrade(100);
		std::cout << song;
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}

void errorCase_increase() {
	std::cout << BLUE << "ERROR CASE - INCREASE" << DEFAULT << std::endl;
	try {
		Bureaucrat park("park", 100);
		std::cout << park;
		park.increaseGrade(100);
		std::cout << park;
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}

void errorCase_init() {
	std::cout << BLUE << "ERROR CASE - INIT" << DEFAULT << std::endl;
	try {
		Bureaucrat shin("shin", 0);
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}

void successCase_decrease() {
	std::cout << BLUE << "SUCCESS CASE - DECREASE" << DEFAULT << std::endl;
	try {
		Bureaucrat choi("choi", 6);
		std::cout << choi;
		choi.decreaseGrade(2);
		std::cout << choi;
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}

void successCase_increase() {
	std::cout << BLUE << "SUCCESS CASE - INCREASE" << DEFAULT << std::endl;
	try {
		Bureaucrat lee("lee", 10);
		std::cout << lee;
		lee.increaseGrade(3);
		std::cout << lee;
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}

void successCase() {
	std::cout << BLUE << "SUCCESS CASE" << DEFAULT << std::endl;
	try {
		Bureaucrat kim("kim", 2);
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}

int main() {
	successCase();
	successCase_increase();
	successCase_decrease();
	errorCase_decrease();
	errorCase_increase();
	errorCase_init();
	return 0;
}
