//
// Created by Temple Tarsha on 12/18/20.
//

#include "AMateria.hpp"

AMateria::AMateria() : _xp(0), _type("default") {}

AMateria::AMateria(const std::string &type) : _type(type) {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria &src) {
	*this = src;
}

AMateria & AMateria::operator=(const AMateria &rhs) {
	if (this == &rhs)
		return *this;
	this->_xp = rhs._xp;
	this->_type = rhs._type;
	return *this;
}

const std::string & AMateria::getType() const {
	return this->_type;
}

unsigned int AMateria::getXP() const {
	return this->_xp;
}

void AMateria::use(ICharacter &target) {
	(void)target;
	_xp += 10;
}