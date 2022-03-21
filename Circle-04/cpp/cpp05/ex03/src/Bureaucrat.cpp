#include "Bureaucrat.hpp"
#include "Color.hpp"

Bureaucrat::Bureaucrat() : name("noname"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& origin) : name(origin.getName()) {
	this->setGrade(origin.getGrade());
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rvalue) {
	this->setGrade(rvalue.getGrade());
	return *this;
}

std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::setGrade(int const grade) {
	this->grade = grade;
}

void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
	}
	catch (std::exception& e) {
		std::cout << RED << this->getName() << " cannot sign " << form.getName() << " because "<< e.what() << DEFAULT << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form) {
	form.execute(*this);
}

void Bureaucrat::increaseGrade(int const amount) {
	if (this->getGrade() - amount < MAX_GRADE) {
		throw GradeTooHighException();
	}
	this->setGrade(this->getGrade() - amount);
	std::cout << GREEN << this->getName() << " grade is succesfully increase! (now : " << this->getGrade() << " )" << DEFAULT << std::endl;
}
void Bureaucrat::decreaseGrade(int const amount) {
	if (this->getGrade() + amount > MIN_GRADE)
		throw GradeTooLowException();
	this->setGrade(this->getGrade() + amount);
	std::cout << GREEN << this->getName() << " grade is succesfully decrease! (now : " << this->getGrade() << " )" << DEFAULT << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "[ERROR] Grade is Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "[ERROR] Grade is Too Low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bu) {
	os << "name : " << bu.getName() << ", grade : " << bu.getGrade() << std::endl;
	return os;
}
