//
// Created by Temple Tarsha on 1/6/21.
//

#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {
	_name = "Fwoosh";
	_effects = "fwooshed";
}

Fwoosh::~Fwoosh() {}

Fwoosh::Fwoosh(const Fwoosh &src) : ASpell(src) {
	*this = src;
}

Fwoosh & Fwoosh::operator=(const Fwoosh &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_effects = rhs._effects;
	}
	return *this;
}

ASpell * Fwoosh::clone() const {
	Fwoosh * clone = new Fwoosh();
	return clone;
}

