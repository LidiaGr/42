//
// Created by Temple Tarsha on 12/15/20.
//

#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <string>
#include <iostream>
#include "Victim.hpp"

class Sorcerer {

private:
	std::string _name;
	std::string _title;
	Sorcerer();

public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(const Sorcerer & src);
	~Sorcerer();

	Sorcerer & operator=(const Sorcerer & rhs);

	std::string getName() const;
	std::string getTitle() const;

	void polymorph(Victim const &) const;
};

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs);

#endif
