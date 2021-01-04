//
// Created by Temple Tarsha on 12/18/20.
//

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
	for (int i = 0; i < 4; i++)
		_materials[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	*this = src;
}

MateriaSource & MateriaSource::operator=(const MateriaSource &rhs) {
	if (this == &rhs)
		return *this;
	for (int i = 0; i < 4; i++) {
		_materials[i] = rhs._materials[i];
	}
	return *this;
}

MateriaSource::~MateriaSource() {}

void MateriaSource::learnMateria(AMateria *mate) {
	if (mate == nullptr)
		return;
	for (int i = 0; i < 4; i++) {
		if (_materials[i] == nullptr) {
			_materials[i] = mate;
			break;
		}
	}
}

AMateria * MateriaSource::createMateria(const std::string &type) {
	AMateria *copy = nullptr;
	for (int i = 0; i < 4; i++) {
		if (_materials[i] != nullptr && _materials[i]->getType() == type)
			copy = _materials[i]->clone();
	}
	return (copy);
}
