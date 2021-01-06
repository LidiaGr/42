//
// Created by Temple Tarsha on 1/6/21.
//

#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}

Dummy::~Dummy() {}

Dummy::Dummy(const Dummy &src) : ATarget(src) {
	*this= src;
}

Dummy & Dummy::operator=(const Dummy & rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

ATarget * Dummy::clone() const {
	Dummy * clone = new Dummy();
	return clone;
}