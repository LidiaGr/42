//
// Created by Lidia Grigoreva on 08/01/2021.
//

#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::~ASpell() {

}

ASpell::ASpell(const ASpell &src) {*this = src;}

ASpell & ASpell::operator=(const ASpell &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_effects = rhs._effects;
	}
	return *this;
}

const std::string &ASpell::getName() const {
	return _name;
}

const std::string &ASpell::getEffects() const {
	return _effects;
}

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects) {}

void ASpell::launch(const ATarget &target) {
	target.getHitBySpell(*this);
}
