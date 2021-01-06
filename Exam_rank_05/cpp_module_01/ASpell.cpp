//
// Created by Temple Tarsha on 1/6/21.
//

#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects) {}

ASpell::ASpell(const ASpell &src) {
	*this = src;
}

ASpell & ASpell::operator=(const ASpell &) {
	return *this;
}

ASpell::~ASpell() {}

std::string ASpell::getName() const {
	return this->_name;
}

std::string ASpell::getEffects() const {
	return this->_effects;
}

void ASpell::launch(const ATarget &target) {
	target.getHitBySpell(*this);
}
