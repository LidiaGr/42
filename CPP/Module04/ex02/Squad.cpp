//
// Created by Temple Tarsha on 12/17/20.
//

#include "Squad.hpp"

Squad::Squad() : ISquad(), _unitsCount(0), _units(nullptr) {}

Squad::~Squad() {
	for (int i = 0; i < _unitsCount; i++) {
		delete _units[i];
	}
	delete [] _units;
}

Squad::Squad(const Squad &src) {
	*this = src;
}

Squad & Squad::operator=(const Squad &rhs) {
	if (this == &rhs)
		return *this;
	if (_units != nullptr) {
		for (int i = 0; i < rhs._unitsCount; i++)
			delete _units[i];
	}
	_units = new ISpaceMarine *[rhs._unitsCount];
	for (int i = 0; i < rhs._unitsCount; i++)
		_units[i] = rhs._units[i];
	return *this;
}

int Squad::getCount() const {
	return this->_unitsCount;
}

ISpaceMarine* Squad::getUnit(int nb) const {
	if (nb < 0 && nb > _unitsCount) {
		return nullptr;
	}
	if (_units != nullptr)
		return _units[nb];
	else
		return nullptr;
}

int Squad::push(ISpaceMarine *marine) {
	if (marine == nullptr)
		return _unitsCount;
	for (int i = 0; i < _unitsCount; i++)
		if (_units[i] == marine)
			return _unitsCount;
	_unitsCount += 1;
	ISpaceMarine **tmp =  new ISpaceMarine *[_unitsCount];
	for (int i = 0; i < _unitsCount - 1; i++)
		tmp[i] = _units[i];
	tmp[_unitsCount - 1] = marine;
	delete [] _units;
	_units = tmp;
	return _unitsCount;
}
