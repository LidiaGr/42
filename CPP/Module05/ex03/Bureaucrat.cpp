//
//  Bureaucrat.cpp
//  Test05
//
//  Created by Temple Tarsha on 12/19/20.
//  Copyright © 2020 Temple Tarsha. All rights reserved.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(0) {};

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	*this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs) {
		getName() = rhs._name;
		this->_grade = rhs._grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

std::ostream & operator<<(std::ostream & o, const Bureaucrat & rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat's grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat's grade is too low";
}

const char *Bureaucrat::DoubleSign::what() const throw() {
	return "Form is already signed";
}

void Bureaucrat::incrementGrade() {
	this->_grade -= 1;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	this->_grade += 1;
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(AForm &form) {
	if (form.getStatus() == 1)
		throw Bureaucrat::DoubleSign();
	if (this->getGrade() <= form.getGradeToSign()) {
		std::cout	<< "Bureaucrat " << this->getName()
				<< " signs form \"" << form.getName() << "\"." << std::endl;
		form.beSigned(*this);
	} else {
		std::cout 	<< "Bureaucrat " << this->getName()
					<< " cannot sign form \"" << form.getName()
					<< "\" because his/her grade is too low." << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) {
	if (form.getStatus() == false) {
		std::cout	<< "Bureaucrat " << this->getName() << " cannot execute the form \""
				<< form.getName() << "\", because the form is unsigned." << std::endl;
		return ;
	}
	if (form.getGradeToExec() >= this->_grade) {
		std::cout	<< "Bureaucrat " << this->getName() << " executes form \""
				<< form.getName() << "\"." << std::endl;
		form.execute(*this);
	}
	else
		std::cout	<< "Bureaucrat " << this->getName() << " cannot execute the form \""
					<< form.getName() << "\", because his/her grade is too low." << std::endl;
}