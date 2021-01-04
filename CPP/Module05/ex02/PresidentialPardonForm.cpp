//
// Created by Temple Tarsha on 12/21/20.
//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default form", 1, 1) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
		: AForm("PresidentialPardonForm", 25, 5),
		  _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
		: AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()) {
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this == &rhs)
		return *this;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	(void)executor;
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
