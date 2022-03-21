#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", S_SIGN_GRADE, S_EXCUTE_GRADE,false), target("notarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", S_SIGN_GRADE, S_EXCUTE_GRADE,false), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& origin) {
	*this = origin;
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
	std::fstream output_file;
	output_file.open(this->getTarget() + "_shrubbery", std::ios::out);
	if (output_file.fail())
		throw FileOpenError();
	output_file << 	"	               ,@@@@@@@,                  \n"
					"       ,,,.   ,@@@@@@/@@,  .oo8888o.         \n"
					"    ,&..&%&&%,@@@@@/@@@@@@,8888/88/8o        \n"
					"   ,%&/%&&%&&%,@@@/@@@/@@@88/88888/88'       \n"
					"   %&&%&%&/%&&%@@/@@/ /@@@88888/88888'       \n"
					"   %&&%/ %&..&&@@/ V /@@' `88/8 `/88'        \n"
					"   `&%/ ` /%&'    |.|        / '|8'          \n"
					"       |o|        | |         | |            \n"
					"       |.|        | |         | |            \n"
					"   /// ._///_/__/  ,/_//__///.  /_//__/_     \n";
}

const char * ShrubberyCreationForm::FileOpenError::what() const throw() {
	return "File Open Error";
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& shrubberyCreationForm) {
	os << "[ShrubberyCreationForm] type : " << shrubberyCreationForm.getTarget() << ", isSigned : " << shrubberyCreationForm.getIsSigned() << std::endl;
	return os;
}
