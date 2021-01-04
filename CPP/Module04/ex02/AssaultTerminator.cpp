//
// Created by Temple Tarsha on 12/17/20.
//

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator() : ISpaceMarine() {
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &src) {
	*this = src;
}

AssaultTerminator::~AssaultTerminator() {
	std::cout << "I’ll be back..." << std::endl;
}

AssaultTerminator & AssaultTerminator::operator=(const AssaultTerminator &rhs) {
	if (this == &rhs) {}
	return *this;
}

ISpaceMarine * AssaultTerminator::clone() const {
	AssaultTerminator * clone = new AssaultTerminator(*this);
	return (clone);
}

void AssaultTerminator::battleCry() const {
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const {
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const {
	std::cout << "* attacks with chainfists *" << std::endl;
}
