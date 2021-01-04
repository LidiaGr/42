//
// Created by Temple Tarsha on 12/18/20.
//

#include "Cure.hpp"

Cure::Cure() : AMateria() {
	_xp = 0;
	_type = "cure";
}

Cure::Cure(const Cure &src) {
	*this = src;
}

Cure::~Cure() {}

Cure & Cure::operator=(const Cure &rhs) {
	if (this == &rhs)
		return *this;
	this->_xp = rhs._xp;
	this->_type = rhs._type;
	return *this;
}

Cure * Cure::clone() const {
	Cure * clone = new Cure(*this);
	return (clone);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	AMateria::use(target);
}