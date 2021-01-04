//
// Created by Temple Tarsha on 12/16/20.
//

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon() {
	_name = "Power Fist";
	_damage = 50;
	_apcost = 8;
}

PowerFist::PowerFist(const std::string &name, int apcost, int damage) : AWeapon(name, apcost, damage) {
	_name = "Power Fist";
	_damage = 50;
	_apcost = 8;
}

PowerFist::~PowerFist() {}

PowerFist::PowerFist(const PowerFist &src) {
	*this = src;
}

PowerFist & PowerFist::operator=(const PowerFist &rhs) {
	this->_name = rhs._name;
	this->_damage = rhs._damage;
	this->_apcost = rhs._apcost;
	return *this;
}

void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
