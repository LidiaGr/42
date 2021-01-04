//
// Created by Temple Tarsha on 12/19/20.
//

#include "Bureaucrat.hpp"
#include <stdexcept>

int main(void)
{
	try {
		Bureaucrat *bob = new Bureaucrat("Bob", -15);
		std::cout << *bob << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat *bob = new Bureaucrat("Bob", 190);
		std::cout << *bob << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat *bob = new Bureaucrat("Bob", 100);
		std::cout << *bob << std::endl;
		delete bob;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat *bob = new Bureaucrat("Bob", 1);
		std::cout << *bob << std::endl;
		bob->decrementGrade();
		std::cout << *bob << std::endl;
		bob->incrementGrade();
		std::cout << *bob << std::endl;
		bob->incrementGrade();
		std::cout << *bob << std::endl;
		delete bob;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat *bob = new Bureaucrat("Bob", 150);
		std::cout << *bob << std::endl;
		delete bob;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
