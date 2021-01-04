//
// Created by Temple Tarsha on 12/21/20.
//

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default form", 1, 1) {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
		: AForm("RobotomyRequestForm", 72, 45),
		  _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
		: AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()) {
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this == &rhs)
		return *this;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	(void)executor;
	std::cout << "Robot makes some drilling noises" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}