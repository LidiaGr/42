//
// Created by Temple Tarsha on 12/20/20.
//

#include "AForm.hpp"

AForm::AForm() {}

AForm::AForm(std::string name, int const gradeToSign, int const gradeToExec)
			: _name(name), _signStatus(false) {
	_gradeToSign = gradeToSign;
	_gradeToExec = gradeToExec;
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw AForm::GradeTooLowException();

}
AForm::~AForm() {}

AForm::AForm(const AForm &src) {
	*this = src;
}

AForm & AForm::operator=(const AForm &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_signStatus = rhs._signStatus;
		this->_gradeToSign = rhs._gradeToSign;
		this->_gradeToExec = rhs._gradeToExec;
	}
	return *this;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Forms's grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Forms's grade is too low";
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= _gradeToSign)
		_signStatus = true;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::string AForm::getName() const {
	return this->_name;
}

int AForm::getStatus() const {
	return this->_signStatus;
}

int AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int AForm::getGradeToExec() const {
	return this->_gradeToExec;
}

std::ostream & operator<<(std::ostream & o, const AForm & rhs) {
	if (rhs.getStatus() == false) {
		o << "Form \"" << rhs.getName() << "\" is unsigned. "
		  << "Grade to sign is " << rhs.getGradeToSign() << ". "
		  << "Grade to execute is " << rhs.getGradeToExec() << ". " << std::endl;
	} else {
		o << "Form \"" << rhs.getName() << "\" is successfully signed." << std::endl;
	}
	return o;
}
