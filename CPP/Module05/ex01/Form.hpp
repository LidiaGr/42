//
// Created by Temple Tarsha on 12/20/20.
//

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
	std::string _name;
	bool	_signStatus;
	int		_gradeToSign;
	int		_gradeToExec;
	Form();

public:
	~Form();
	Form(const Form & src);
	Form(std::string name, int const gradeToSign, int const gradeToExec);

	Form & operator=(const Form & rhs);

	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();};
	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();};

	std::string getName() const;
	int getStatus() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	void beSigned(Bureaucrat & bureaucrat);
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);


#endif
