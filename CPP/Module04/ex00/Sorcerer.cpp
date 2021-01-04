//
// Created by Temple Tarsha on 12/15/20.
//

#include "Sorcerer.hpp"

Sorcerer::Sorcerer() { }

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer() {
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &src) {
	*this = src;
}

Sorcerer & Sorcerer::operator=(const Sorcerer & rhs) {
	this->_name = rhs._name;
	this->_title = rhs._title;
	return *this;
}

std::string Sorcerer::getName() const {
	return this->_name;
}

std::string Sorcerer::getTitle() const {
	return this->_title;
}

std::ostream & operator<<(std::ostream & o, const Sorcerer & rhs) {
	o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies!" << std::endl;
	return o;
}

void Sorcerer::polymorph(const Victim & vic) const {
	vic.getPolymorphed();
}