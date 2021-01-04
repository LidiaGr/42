//
// Created by Temple Tarsha on 12/21/20.
//

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

public:
	Intern();
	~Intern();
	Intern(const Intern & src);

	Intern & operator=(const Intern &);

	AForm *makeForm(std::string formName, std::string target);
	AForm *createShrubbery(std::string target);
	AForm *createRobotomy(std::string target);
	AForm *createPardon(std::string target);

	class UnknownForm : public std::exception {
		virtual const char *what() const throw();};
};

#endif
