#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP

#include <string>
#include <iostream>
#include <time.h>
#include <exception>
#include "Bureaucrat.hpp"

#define P_SIGN_GRADE 25
#define P_EXCUTE_GRADE 5

class Bureaucrat;

class PresidentialPardonForm : public Form {
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm&);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm&);

		const std::string getTarget() const;
		void setTarget(std::string target);
		void action() const;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& PresidentialPardonForm);

#endif
