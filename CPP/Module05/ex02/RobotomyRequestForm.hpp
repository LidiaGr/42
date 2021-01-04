//
// Created by Temple Tarsha on 12/21/20.
//

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

private:
	std::string _target;
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm & src);
	RobotomyRequestForm & operator=(const RobotomyRequestForm & rhs);

public:
	RobotomyRequestForm(std::string const & target);
	~RobotomyRequestForm();

	virtual void execute(Bureaucrat const & executor) const;
};


#endif
