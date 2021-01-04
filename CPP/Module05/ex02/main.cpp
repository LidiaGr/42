//
// Created by Temple Tarsha on 12/19/20.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdexcept>

int main(void)
{
	try {
		Bureaucrat *bob = new Bureaucrat("Bob", 15);
		AForm *form = new ShrubberyCreationForm("Tree");
		std::cout << *bob;
		std::cout << *form;
		bob->signForm(*form);
		std::cout << *form;
		bob->executeForm(*form);
		delete bob;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "_________________________________________" <<  std::endl;
	try {
		Bureaucrat bob("Bob", 1);
		std::cout << bob;
		AForm *form = new RobotomyRequestForm("CPP Modules");
		std::cout << *form;
		bob.signForm(*form);
		bob.executeForm(*form);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "_________________________________________" <<  std::endl;
	try {
		Bureaucrat bob("Bob", 100);
		std::cout << bob;
		AForm *form = new PresidentialPardonForm("You");
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
		AForm *form = new PresidentialPardonForm("You");
		std::cout << *form;
		bob.signForm(*form);
		bob.executeForm(*form);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
