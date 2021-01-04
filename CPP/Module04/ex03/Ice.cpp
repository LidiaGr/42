//
// Created by Temple Tarsha on 12/18/20.
//

#include "Ice.hpp"

Ice::Ice() : AMateria() {
	_xp = 0;
	_type = "ice";
}

Ice::Ice(const Ice &src) {
	*this = src;
}

Ice::~Ice() {}

Ice & Ice::operator=(const Ice &rhs) {
	if (this == &rhs)
		return *this;
	this->_xp = rhs._xp;
	this->_type = rhs._type;
	return *this;
}

Ice * Ice::clone() const {
	Ice * clone = new Ice(*this);
	return (clone);
}


void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	AMateria::use(target);
}