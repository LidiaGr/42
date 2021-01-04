//
// Created by Temple Tarsha on 12/20/20.
//

#include "Form.hpp"

Form::Form() {}

Form::Form(std::string name, int const gradeToSign, int const gradeToExec)
			: _name(name), _signStatus(false) {
	_gradeToSign = gradeToSign;
	_gradeToExec = gradeToExec;
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw Form::GradeTooLowException();

}

Form::~Form() {}

Form::Form(const Form &src) {
	*this = src;
}

Form & Form::operator=(const Form &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_signStatus = rhs._signStatus;
		this->_gradeToSign = rhs._gradeToSign;
		this->_gradeToExec = rhs._gradeToExec;
	}
	return *this;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Forms's grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Forms's grade is too low";
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= _gradeToSign)
		_signStatus = true;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::string Form::getName() const {
	return this->_name;
}

int Form::getStatus() const {
	return this->_signStatus;
}

int Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int Form::getGradeToExec() const {
	return this->_gradeToExec;
}

std::ostream & operator<<(std::ostream & o, const Form & rhs) {
	if (rhs.getStatus() == false) {
		o << "Form \"" << rhs.getName() << "\" is unsigned. "
		  << "Grade to sign is " << rhs.getGradeToSign() << ". "
		  << "Grade to execute is " << rhs.getGradeToExec() << ". " << std::endl;
	} else {
		o << "Form \"" << rhs.getName() << "\" is successfully signed." << std::endl;
	}
	return o;
}
