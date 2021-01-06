//
// Created by Temple Tarsha on 1/6/21.
//

#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string type) : _type(type) {}

ATarget::ATarget(const ATarget &src) {
	*this = src;
}

ATarget & ATarget::operator=(const ATarget &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

ATarget::~ATarget() {}

std::string ATarget::getType() const {
	return this->_type;
}

void ATarget::getHitBySpell(const ASpell &spell) const {
	std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
}
