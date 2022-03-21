#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern {
    private:
    public:
		Intern();
		Intern(const Intern&);
		~Intern();

		Intern& operator=(const Intern&);
		Form* shrubbery(std::string formTarget);
		Form* robotomy(std::string formTarget);
		Form* presidential(std::string formTarget);
		Form *makeForm(std::string formType, std::string formTarget);

	class NotExistFormType : public std::exception {
		const char * what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Intern& bu);

#endif


