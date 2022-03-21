#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", P_SIGN_GRADE, P_EXCUTE_GRADE, false), target("notarget") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", P_SIGN_GRADE, P_EXCUTE_GRADE, false), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& origin) {
	*this = origin;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rvalue) {
	this->setIsSigned(rvalue.getIsSigned());
	this->setTarget(rvalue.getTarget());
	return *this;
}

const std::string PresidentialPardonForm::getTarget() const {
	return this->target;
}
void PresidentialPardonForm::setTarget(std::string target) {
	this->target = target;
}
void PresidentialPardonForm::action() const {
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& presidentialPardonForm) {
	os << "[PresidentialPardonForm] type : " << presidentialPardonForm.getTarget() << ", isSigned : " << presidentialPardonForm.getIsSigned() << std::endl;
	return os;
}
