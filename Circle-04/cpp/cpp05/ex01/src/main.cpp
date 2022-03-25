#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Color.hpp"

void errorCase_signGrade() {
	std::cout << BLUE << "ERROR CASE - SIGN GRADE" << DEFAULT << std::endl;
	try {
		Form b("b", 151, 1, false);
		std::cout << b;
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}

void errorCase_executeGrade() {
	std::cout << BLUE << "ERROR CASE - EXCUTE GRADE" << DEFAULT << std::endl;
	try {
		Form c("c", 1, 0, false);
		std::cout << c;
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}

void successCase_errorCase() {
	std::cout << BLUE << "SUCCESS CASE + ERROR CASE" << DEFAULT << std::endl;
	try {
		Bureaucrat bu("bu", 100);
		Form form1("form1", 110, 20, false);
		Form form2("form2", 80, 59, false);

		bu.signForm(form1);
		bu.signForm(form2);
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}

void successCase() {
	std::cout << BLUE << "SUCCESS CASE" << DEFAULT << std::endl;
	try {
		Form a("a", 1, 1, false);
		std::cout << a;
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}

int main() {
	successCase();
	errorCase_signGrade();
	errorCase_executeGrade();
	successCase_errorCase();
	return 0;
}
