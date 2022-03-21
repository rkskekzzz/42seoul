#include "Intern.hpp"
#include "Color.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& obj) {
    *this = obj;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& obj) {
	(void)obj;
    return *this;
}

Form* Intern::shrubbery(std::string formTarget) {
	return new ShrubberyCreationForm(formTarget);
}
Form* Intern::robotomy(std::string formTarget) {
	return new RobotomyRequestForm(formTarget);
}
Form* Intern::presidential(std::string formTarget) {
	return new PresidentialPardonForm(formTarget);
}

Form* Intern::makeForm(std::string formType, std::string formTarget) {
	std::string type[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form* (Intern::*farray[3])(std::string) = {&Intern::shrubbery, &Intern::robotomy, &Intern::presidential};

	int index = 0;
	for (; index < 3 ; index++)
		if (type[index] == formType)
			break;
	if (index == 3)
		throw NotExistFormType();
	std::cout << GREEN << "Intern make " << formType << "(target : " << formTarget << ")" << std::endl;
	return (this->*farray[index])(formTarget) ;
}

const char * Intern::NotExistFormType::what() const throw() {
	return "Not Exist From Type!";
}
