//
// Created by Temple Tarsha on 12/21/20.
//

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

private:
	std::string _target;
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm & src);
	ShrubberyCreationForm & operator=(const ShrubberyCreationForm & rhs);

public:
	ShrubberyCreationForm(std::string const & target);
	~ShrubberyCreationForm();

	virtual void execute(Bureaucrat const & executor) const;
};


#endif
