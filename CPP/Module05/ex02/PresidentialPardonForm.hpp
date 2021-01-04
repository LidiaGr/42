//
// Created by Temple Tarsha on 12/21/20.
//

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

private:
	std::string _target;
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm & src);
	PresidentialPardonForm & operator=(const PresidentialPardonForm & rhs);

public:
	PresidentialPardonForm(std::string const & target);
	~PresidentialPardonForm();

	virtual void execute(Bureaucrat const & executor) const;
};


#endif
