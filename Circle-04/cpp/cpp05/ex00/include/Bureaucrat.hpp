#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat {
    private:
		const std::string name;
		int grade;
    public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat&);

		std::string getName() const;
		int getGrade() const;
		void setGrade(int const grade);
		void increaseGrade(int const grade);
		void decreaseGrade(int const grade);

		class GradeTooHighException : public std::exception {
			const char * what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char * what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bu);

#endif


