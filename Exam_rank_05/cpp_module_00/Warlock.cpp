//
// Created by Temple Tarsha on 1/4/21.
//

#include "Warlock.hpp"

Warlock::~Warlock() {
	std::cout << this->getName() << ": My job here is done!" << std::endl;
}

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

std::string Warlock::getName() const {
	return this->_name;
}

std::string Warlock::getTitle() const {
	return this->_title;
}

void Warlock::setTitle(std::string info) {
	this->_title = info;
}

void Warlock::introduce() const {
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}
