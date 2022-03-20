#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat: public std::exception {
    protected:
		const std::string name;
		const int grade;
    public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat();

		GradeTooLowException();

		Bureaucrat& operator=(const Bureaucrat&);
};


#endif


