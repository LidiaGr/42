//
//  Bureaucrat.hpp
//  Test05
//
//  Created by Temple Tarsha on 12/19/20.
//  Copyright © 2020 Temple Tarsha. All rights reserved.
//

#ifndef Bureaucrat_hpp
#define Bureaucrat_hpp

#include <iostream>

class Bureaucrat {

private:
	std::string const _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &rhs);

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();};
	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif /* Bureaucrat_hpp */
