//
// Created by Temple Tarsha on 12/16/20.
//

#include "Peon.hpp"

Peon::Peon() : Victim() {}

Peon::Peon(std::string name) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon() {
	std::cout << "Bleuark..." << std::endl;
}

Peon & Peon::operator=(const Peon *rhs) {
	this->_name = rhs->_name;
	return *this;
}

Peon::Peon(const Peon &src) {
	*this = src;
}

void Peon::getPolymorphed() const {
	std::cout << _name << " has been turned into a pink pony!" << std::endl;
}
