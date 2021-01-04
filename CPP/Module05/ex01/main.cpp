//
// Created by Temple Tarsha on 12/19/20.
//

#include "Bureaucrat.hpp"
#include <stdexcept>

int main(void)
{
	try {
		Bureaucrat *bob = new Bureaucrat("Bob", 15);
		Form *form = new Form("Form1", 16, 108);
		std::cout << *bob;
		std::cout << *form;
		bob->signForm(*form);
		bob->signForm(*form);
		std::cout << *form;
		delete bob;
		delete form;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "_________________________________________" <<  std::endl;
	try {
		Bureaucrat bob("Bob", 1);
		std::cout << bob;
		Form *form = new Form("Form1", 0, 18);
		std::cout << *form;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "_________________________________________" <<  std::endl;
	try {
		Bureaucrat bob("Bob", 100);
		std::cout << bob;
		Form form("Form1", 5, 151);
		std::cout << form;
		bob.signForm(form);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "_________________________________________" <<  std::endl;
	try {
		Bureaucrat bob("Bob", 150);
		std::cout << bob;
		Form form("Form1", 150, 10);
		std::cout << form;
		bob.signForm(form);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
