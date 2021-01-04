//
// Created by Temple Tarsha on 12/21/20.
//

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default form", 1, 1) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
						: AForm("ShrubberyCreationForm", 145, 137),
						_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
						: AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this == &rhs)
		return *this;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	(void)executor;
	std::ofstream file(_target + "_shrubbery");
	file <<	" _\n"
	 		"| |\n"
			"| |_ _ __ ___  ___\n"
			"| __| '__/ _ \\/ _ \\\n"
			"| |_| | |  __/  __/\n"
			" \\__|_|  \\___|\\___|\n";
}