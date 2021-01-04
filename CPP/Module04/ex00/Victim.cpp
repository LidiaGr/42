//
// Created by Temple Tarsha on 12/16/20.
//

#include "Victim.hpp"

Victim::Victim() {}

Victim::Victim(std::string name) : _name(name) {
	std::cout << "Some random victim called " << _name << " just appeared!" << std::endl;
}

Victim::~Victim() {
	std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}

Victim & Victim::operator=(const Victim &rhs) {
	this->_name = rhs._name;
	return *this;
}

Victim::Victim(const Victim &src) {
	*this = src;
}

std::string Victim::getName() const {
	return this->_name;
}

std::ostream & operator<<(std::ostream & o, const Victim & rhs) {
	o << "I am " << rhs.getName() << " and I like otters!" << std::endl;
	return o;
}

void Victim::getPolymorphed() const {
	std::cout << _name << " has been turned into a cute little sheep!" << std::endl;
}
