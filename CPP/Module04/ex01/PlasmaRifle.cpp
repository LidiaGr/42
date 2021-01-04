//
// Created by Temple Tarsha on 12/16/20.
//

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon() {
	_name = "Plasma Rifle";
	_damage = 21;
	_apcost = 5;
}

PlasmaRifle::PlasmaRifle(const std::string &name, int apcost, int damage) : AWeapon(name, apcost, damage) {
	_name = "Plasma Rifle";
	_damage = 21;
	_apcost = 5;
}

PlasmaRifle::~PlasmaRifle() {}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &src) {
	*this = src;
}

PlasmaRifle & PlasmaRifle::operator=(const PlasmaRifle &rhs) {
	this->_name = rhs._name;
	this->_damage = rhs._damage;
	this->_apcost = rhs._apcost;
	return *this;
}

void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
