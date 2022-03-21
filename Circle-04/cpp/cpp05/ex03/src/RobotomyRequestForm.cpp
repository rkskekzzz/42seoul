#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", R_SIGN_GRADE, R_EXCUTE_GRADE, false), target("notarget") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", R_SIGN_GRADE, R_EXCUTE_GRADE, false), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& origin) {
	*this = origin;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rvalue) {
	this->setIsSigned(rvalue.getIsSigned());
	this->setTarget(rvalue.getTarget());
	return *this;
}

const std::string RobotomyRequestForm::getTarget() const {
	return this->target;
}
void RobotomyRequestForm::setTarget(std::string target) {
	this->target = target;
}
void RobotomyRequestForm::action() const {
	std::cout << ".....drill" << std::endl;
	srand (time(NULL));
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully!!" << std::endl;
	else
		std::cout << this->getTarget() << " failed..." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& robotomyRequestForm) {
	os << "[RobotomyRequestForm] type : " << robotomyRequestForm.getTarget() << ", isSigned : " << robotomyRequestForm.getIsSigned() << std::endl;
	return os;
}
