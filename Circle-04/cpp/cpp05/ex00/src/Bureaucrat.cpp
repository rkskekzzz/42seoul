#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :name("noname"), grade(150) {
	std::cout << "[Bureaucrat] Constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
	if (grade < 0)
		throw  Bureaucrat::GradeTooLowException;
	std::cout << "[Bureaucrat] Constructor called!" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "[Bureaucrat] Destructor called!" << std::endl;
}
