//
// Created by Temple Tarsha on 1/6/21.
//

#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {
	_name = "Fireball";
	_effects = "burnt to a crisp";
}

Fireball::~Fireball() {}

Fireball::Fireball(const Fireball &src) : ASpell(src) {
	*this = src;
}

Fireball & Fireball::operator=(const Fireball &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_effects = rhs._effects;
	}
	return *this;
}

ASpell * Fireball::clone() const {
	Fireball * clone = new Fireball();
	return clone;
}
