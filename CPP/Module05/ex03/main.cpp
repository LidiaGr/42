//
// Created by Temple Tarsha on 12/19/20.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <stdexcept>

int main(void)
{
	srand(time(nullptr));
	try {
		Bureaucrat bob("Bob", 1);
		Intern nobody;
		AForm *form;

		form = nobody.makeForm("robotomy request", "Bender");
		std::cout << *form;
		bob.signForm(*form);
		std::cout << *form;
		bob.executeForm(*form);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "_________________________________________" <<  std::endl;
	try {
		Bureaucrat bob("Bob", 1);
		std::cout << bob;
		Intern nobody;
		AForm *form = nobody.makeForm("impossible request", "You");

		std::cout << *form;
		bob.executeForm(*form);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "_________________________________________" <<  std::endl;
	try {
		Bureaucrat bob("Bob", 100);
		std::cout << bob;
		Intern nobody;
		AForm *form = nobody.makeForm("presidential pardon", "You");

		std::cout << *form;
		bob.signForm(*form);
		bob.executeForm(*form);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "_________________________________________" <<  std::endl;
	try {
		Bureaucrat bob("Bob", 5);
		std::cout << bob;
		Intern nobody;
		AForm *form = nobody.makeForm("shrubbery creation", "Tree");

		std::cout << *form;
		bob.signForm(*form);
		bob.executeForm(*form);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
