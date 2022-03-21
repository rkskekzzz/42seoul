#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Color.hpp"

void successCase_presi() {
	std::cout << BLUE << "<ERROR CASE - formIsNotSigned>" << DEFAULT << std::endl;
	try {
		Bureaucrat signer("signer", P_SIGN_GRADE - 1);
		std::cout << signer;
		Bureaucrat excutor("excutor", P_EXCUTE_GRADE - 1);
		std::cout << excutor;
		PresidentialPardonForm form_a("form_a");
		std::cout << form_a;
		signer.signForm(form_a);
		form_a.execute(excutor);
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}

void errorCase_gradeIsTooLow_presi() {
	std::cout << BLUE << "<ERROR CASE - formIsNotSigned>" << DEFAULT << std::endl;
	try {
		Bureaucrat signer("signer", P_SIGN_GRADE - 1);
		std::cout << signer;
		Bureaucrat excutor("excutor", P_EXCUTE_GRADE - 1);
		std::cout << excutor;
		PresidentialPardonForm form_a("form_a");
		std::cout << form_a;
		// signer.signForm(form_a);
		excutor.executeForm(form_a);
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}


void errorCase_gradeIsTooLow_roboto() {
	std::cout << BLUE << "<ERROR CASE - formIsNotSigned>" << DEFAULT << std::endl;
	try {
		Bureaucrat signer("signer", R_SIGN_GRADE - 1);
		std::cout << signer;
		Bureaucrat excutor("excutor", R_EXCUTE_GRADE - 1);
		std::cout << excutor;
		RobotomyRequestForm form_a("form_a");
		std::cout << form_a;
		signer.signForm(form_a);
		excutor.executeForm(form_a);
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}

void successCase_roboto() {
	std::cout << BLUE << "<ERROR CASE - formIsNotSigned>" << DEFAULT << std::endl;
	try {
		Bureaucrat signer("signer", S_SIGN_GRADE - 1);
		std::cout << signer;
		Bureaucrat excutor("excutor", S_EXCUTE_GRADE - 1);
		std::cout << excutor;
		ShrubberyCreationForm form_a("form_a");
		std::cout << form_a;
		signer.signForm(form_a);
		excutor.executeForm(form_a);
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}

void errorCase_formIsNotSigned() {
	std::cout << BLUE << "<ERROR CASE - formIsNotSigned>" << DEFAULT << std::endl;
	try {
		Bureaucrat signer("signer", S_SIGN_GRADE - 1);
		std::cout << signer;
		Bureaucrat excutor("excutor", S_EXCUTE_GRADE - 1);
		std::cout << excutor;
		ShrubberyCreationForm form_a("form_a");
		std::cout << form_a;
		// form_a.beSigned(signer);
		form_a.execute(excutor);
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}

void errorCase_gradeIsTooLow() {
	std::cout << BLUE << "<ERROR CASE - gradeIsTooLow>" << DEFAULT << std::endl;
	try {
		Bureaucrat signer("signer", S_SIGN_GRADE - 1);
		std::cout << signer;
		Bureaucrat excutor("excutor", S_EXCUTE_GRADE + 1);
		std::cout << excutor;
		ShrubberyCreationForm form_a("form_a");
		std::cout << form_a;
		form_a.beSigned(signer);
		form_a.execute(excutor);
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}

void successCase() {
	std::cout << BLUE << "<SUCCESS CASE>" << DEFAULT << std::endl;
	try {
		Bureaucrat signer("signer", S_SIGN_GRADE - 1);
		std::cout << signer;
		Bureaucrat excutor("excutor", S_EXCUTE_GRADE - 1);
		std::cout << excutor;
		ShrubberyCreationForm form_a("form_a");
		std::cout << form_a;
		form_a.beSigned(signer);
		form_a.execute(excutor);
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
	}
}

int main() {
	// successCase();
	// errorCase_gradeIsTooLow();
	// errorCase_formIsNotSigned();

	// successCase_roboto();
	// errorCase_gradeIsTooLow_roboto();

	// successCase_presi();
	// errorCase_gradeIsTooLow_presi();
	Intern  someRandomIntern;
	Form*   rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf;
	return 0;
}
