#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name;
		const int signGrade;
		const int excuteGrade;
		bool isSigned;

	public:
		Form();
		Form(const std::string name, const int signGrade, const int excuteGrade, const bool isSigned);
		Form(const Form&);
		~Form();
		Form& operator=(const Form&);

		const std::string getName() const;
		int getSignGrade() const;
		int getExcuteGrade() const;
		bool getIsSigned() const;
		void setIsSigned(bool b);

		void beSigned(Bureaucrat&);

		class GradeTooHighException : public std::exception {
			const char * what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char * what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
