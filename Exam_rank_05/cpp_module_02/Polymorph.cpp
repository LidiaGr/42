//
// Created by Temple Tarsha on 1/6/21.
//

#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {
	_name = "Polymorph";
	_effects = "turned into a critter";
}

Polymorph::~Polymorph() {}

Polymorph::Polymorph(const Polymorph &src) : ASpell(src) {
	*this = src;
}

Polymorph & Polymorph::operator=(const Polymorph &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_effects = rhs._effects;
	}
	return *this;
}

ASpell * Polymorph::clone() const {
	Polymorph * clone = new Polymorph();
	return clone;
}
