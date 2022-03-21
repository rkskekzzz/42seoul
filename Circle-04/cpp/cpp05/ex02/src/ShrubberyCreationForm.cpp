#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137,false), target("notarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137,false), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& origin) : target(origin.getTarget()) {

}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rvalue) {
	this->setIsSigned(rvalue.getIsSigned());
	this->setTarget(rvalue.getTarget());
	return *this;
}

const std::string ShrubberyCreationForm::getTarget() const {
	return this->target;
}
void ShrubberyCreationForm::setTarget(std::string target) {
	this->target = target;
}
void ShrubberyCreationForm::action() const {

}
