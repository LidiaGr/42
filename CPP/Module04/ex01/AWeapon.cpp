//
// Created by Temple Tarsha on 12/16/20.
//

#include "AWeapon.hpp"

AWeapon::AWeapon() {}

AWeapon::AWeapon(const std::string &name, int apcost, int damage)
				: _name(name), _apcost(apcost), _damage(damage) {}

AWeapon::~AWeapon() {}

AWeapon::AWeapon(const AWeapon &src) {
	*this = src;
}

AWeapon & AWeapon::operator=(const AWeapon &rhs) {
	this->_name = rhs._name;
	this->_damage = rhs._damage;
	this->_apcost = rhs._apcost;
	return *this;
}

std::string AWeapon::getName() const {
	return this->_name;
}

int AWeapon::getDamage() const {
	return this->_damage;
}

int AWeapon::getAPCost() const {
	return this->_apcost;
}
