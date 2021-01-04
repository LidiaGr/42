//
// Created by Temple Tarsha on 12/21/20.
//

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern & Intern::operator=(const Intern &) {
	return *this;
}

AForm * Intern::createShrubbery(std::string target) {
	ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm(target);
	return shrubbery;
}

AForm * Intern::createRobotomy(std::string target) {
	RobotomyRequestForm *robotomy = new RobotomyRequestForm(target);
	return robotomy;
}

AForm * Intern::createPardon(std::string target) {
	PresidentialPardonForm *pardon = new PresidentialPardonForm(target);
	return pardon;
}

const char *Intern::UnknownForm::what() const throw() {
	return "Unknown Form";
}

AForm * Intern::makeForm(std::string formName, std::string target) {
	std::string methodNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm *methodExec[3] = {Intern::createRobotomy(target), Intern::createPardon(target), Intern::createShrubbery(target)};

	for(int i = 0; i < 3; i++) {
		if (methodNames[i].compare(formName) == 0) {
			std::cout << "Intern creates \"" << formName << "\""
					  << " targeted on " << target << std::endl;
			AForm *res = methodExec[i];
			return (res);
		}
	}
	std::cout << "Form \"" << formName << "\" is unknown." << std::endl;
	throw Intern::UnknownForm();
}