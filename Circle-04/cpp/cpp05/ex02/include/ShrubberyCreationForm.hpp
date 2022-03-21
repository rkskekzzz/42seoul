#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form {
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);

		const std::string getTarget() const;
		void setTarget(std::string target);
		void action() const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& shrubberyCreationForm);

#endif
