#include "Form.hpp"
#include "Color.hpp"

Form::Form() : name("noname"), signGrade(MIN_GRADE), excuteGrade(MIN_GRADE), isSigned(false) {}

Form::Form(const Form& obj) : name(obj.getName()), signGrade(obj.getSignGrade()), excuteGrade(obj.getExcuteGrade()) {
    this->setIsSigned(obj.getIsSigned());
}

Form::Form(const std::string name, const int signGrade, const int excuteGrade, const bool isSigned) : name(name), signGrade(signGrade), excuteGrade(excuteGrade), isSigned(isSigned) {
	if (signGrade < 1 || excuteGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || excuteGrade > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form& Form::operator=(const Form& obj) {
    this->setIsSigned(obj.getIsSigned());
    return *this;
}

const std::string Form::getName() const {
    return (this->name);
}

int Form::getSignGrade() const {
    return (this->signGrade);
}

int Form::getExcuteGrade() const {
    return (this->excuteGrade);
}

bool Form::getIsSigned() const {
    return (this->isSigned);
}

void Form::setIsSigned(bool signed_) {
    this->isSigned = signed_;
}

void Form::beSigned(Bureaucrat& signer) {
	if (this->getSignGrade() < signer.getGrade()) {
		throw GradeTooLowException();
	}
    this->setIsSigned(true);
	std::cout << GREEN << signer.getName() << " signs " << this->getName() << DEFAULT << std::endl;
}

void Form::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false)
		throw FormIsNotSigned();
	if (this->getExcuteGrade() < executor.getGrade())
		throw GradeTooLowException();
	this->action();
	std::cout << GREEN << executor.getName() << " excute " << this->getName() << DEFAULT << std::endl;
}

const char* Form::FormIsNotSigned::what() const throw() {
	return "[ERROR] Form is Not Signed";
}

const char* Form::GradeTooHighException::what() const throw() {
	return "[ERROR] Grade is Too High";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "[ERROR] Grade is Too Low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "name : " << form.getName() << ", signGrade : " << form.getSignGrade() << ", executeGrade : " << form.getExcuteGrade() << ", isSign : " << form.getIsSigned() << std::endl;
	return os;
}
