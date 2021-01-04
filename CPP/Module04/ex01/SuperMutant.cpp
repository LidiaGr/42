//
// Created by Temple Tarsha on 12/16/20.
//

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant() {
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &src) {
	*this = src;
}

SuperMutant & SuperMutant::operator=(const SuperMutant &rhs) {
	this->_hp = rhs._hp;
	this->_type = rhs._type;
	return *this;
}

void SuperMutant::takeDamage(int dmg) {
	if ((dmg - 3) >= 0)
		_hp -= (dmg - 3);
}