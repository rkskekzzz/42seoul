#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <time.h>
#include <exception>
#include "Bureaucrat.hpp"

#define R_SIGN_GRADE 72
#define R_EXCUTE_GRADE 45

class Bureaucrat;

class RobotomyRequestForm : public Form {
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm&);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm&);

		const std::string getTarget() const;
		void setTarget(std::string target);
		void action() const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& robotomyRequestForm);

#endif
