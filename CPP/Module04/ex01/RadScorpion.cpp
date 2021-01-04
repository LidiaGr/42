//
// Created by Temple Tarsha on 12/16/20.
//

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion() {
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &src) {
	*this = src;
}

RadScorpion & RadScorpion::operator=(const RadScorpion &rhs) {
	this->_hp = rhs._hp;
	this->_type = rhs._type;
	return *this;
}

