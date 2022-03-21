#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Color.hpp"

void errorCase_signGrade() {
	std::cout << BLUE << "ERROR CASE - SIGN GRADE" << DEFAULT << std::endl;

}

void errorCase_executeGrade() {
	std::cout << BLUE << "ERROR CASE - EXCUTE GRADE" << DEFAULT << std::endl;

}

void successCase_errorCase() {
	std::cout << BLUE << "SUCCESS CASE + ERROR CASE" << DEFAULT << std::endl;

}

void successCase() {
	std::cout << BLUE << "SUCCESS CASE" << DEFAULT << std::endl;

}

int main() {
	successCase();
	errorCase_signGrade();
	errorCase_executeGrade();
	successCase_errorCase();
	return 0;
}
