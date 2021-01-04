//
// Created by Temple Tarsha on 12/17/20.
//

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine() : ISpaceMarine() {
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine &src) {
	*this = src;
}

TacticalMarine::~TacticalMarine() {
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine & TacticalMarine::operator=(const TacticalMarine &rhs) {
	if (this == &rhs) {}
	return *this;
}

ISpaceMarine * TacticalMarine::clone() const {
	TacticalMarine * clone = new TacticalMarine(*this);
	return (clone);
}

void TacticalMarine::battleCry() const {
	std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack() const {
	std::cout << "* attacks with a bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const {
	std::cout << "* attacks with a chainsword *" << std::endl;
}