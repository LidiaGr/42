//
// Created by Temple Tarsha on 12/18/20.
//

#include "Character.hpp"

Character::Character() : ICharacter(), _name("Default") {
	for (int i = 0; i < 4; i++)
		_materia[i] = nullptr;
}

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_materia[i] = nullptr;
}

Character::Character(const Character &src) {
	*this = src;
}

Character & Character::operator=(const Character &rhs) {
	if (this == &rhs)
		return *this;
	for (int i = 0; i < 4; i++) {
		if (_materia[i] != nullptr)
			delete _materia[i];
	}
	this->_name = rhs._name;
	for (int i = 0; i < 4; i++) {
		_materia[i] = rhs._materia[i];
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_materia[i] != nullptr)
			delete _materia[i];
	}
}

const std::string & Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria *m) {
	if (m == nullptr)
		return ;
	for (int i = 0; i < 4; i++) {
		if (_materia[i] == nullptr) {
			_materia[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	if (_materia[idx] == nullptr)
		return ;
	_materia[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3)
		return ;
	if (_materia[idx] == nullptr)
		return ;
	_materia[idx]->use(target);
}