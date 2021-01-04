//
// Created by Temple Tarsha on 12/20/20.
//

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

private:
	std::string _name;
	bool	_signStatus;
	int		_gradeToSign;
	int		_gradeToExec;
	AForm();

public:
	~AForm();
	AForm(const AForm & src);
	AForm(std::string name, int const gradeToSign, int const gradeToExec);

	AForm & operator=(const AForm & rhs);

	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();};
	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();};

	std::string getName() const;
	int getStatus() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	void beSigned(Bureaucrat & bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);


#endif
