//
// Created by Temple Tarsha on 12/16/20.
//

#include "Enemy.hpp"

Enemy::Enemy() : _hp(0), _type("default") {}

Enemy::Enemy(int hp, const std::string &type) : _hp(hp), _type(type) {}

Enemy::~Enemy() {}

Enemy::Enemy(const Enemy &src) {
	*this = src;
}

Enemy & Enemy::operator=(const Enemy &rhs) {
	this->_hp = rhs._hp;
	this->_type = rhs._type;
	return *this;
}

int Enemy::getHP() const {
	return this->_hp;
}

std::string Enemy::getType() const {
	return this->_type;
}

void Enemy::takeDamage(int dmg) {
	if (dmg >= 0)
		_hp -= dmg;
}