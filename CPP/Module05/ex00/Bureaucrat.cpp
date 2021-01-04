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
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat's grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat's grade is too low";
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