//
// Created by Lidia Grigoreva on 08/01/2021.
//

#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::~ATarget() {

}

ATarget::ATarget(const ATarget &src) {*this = src;}

ATarget & ATarget::operator=(const ATarget &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

const std::string &ATarget::getType() const {
	return _type;
}

ATarget::ATarget(std::string type) : _type(type) {}

void ATarget::getHitBySpell(const ASpell &spell) const {
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}