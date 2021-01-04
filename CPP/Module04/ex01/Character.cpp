//
// Created by Temple Tarsha on 12/16/20.
//

#include "Character.hpp"

Character::Character() {}

Character::Character(const std::string &name) : _name(name) {
	_ap = 40;
	_weapon = nullptr;
}

Character::~Character() {}

Character::Character(const Character &src) {
	*this = src;
}

Character & Character::operator=(const Character &rhs) {
	this->_name = rhs._name;
	this->_ap = rhs._ap;
	this->_weapon = rhs._weapon;
	return *this;
}

void Character::recoverAP() {
	if ((_ap + 10) <= 40)
		_ap += 10;
}

void Character::equip(AWeapon *weapon) {
	_weapon = weapon;
}

void Character::attack(Enemy *enemy) {
	if (_weapon && _ap >= _weapon->getAPCost())
	{
		std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() <<  std::endl;
		_weapon->attack();
		enemy->takeDamage(_weapon->getDamage());
		_ap -= _weapon->getAPCost();
	}
	if (enemy->getHP() <= 0) {
		delete enemy;
	}
}

std::string Character::getName() const {
	return this->_name;
}

int Character::getAP() const {
	return this->_ap;
}

AWeapon *Character::getWeapon() const {
	return this->_weapon;
}

std::ostream & operator<<(std::ostream & o, const Character & rhs) {
	if (rhs.getWeapon())
		o << rhs.getName() << " has " << rhs.getAP() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
	else
		o << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << std::endl;
	return o;
}
