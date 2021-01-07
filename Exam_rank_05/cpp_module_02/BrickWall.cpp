//
// Created by Temple Tarsha on 1/6/21.
//

#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::~BrickWall() {}

BrickWall::BrickWall(const BrickWall &src) : ATarget(src) {
	*this= src;
}

BrickWall & BrickWall::operator=(const BrickWall & rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

ATarget * BrickWall::clone() const {
	BrickWall * clone = new BrickWall();
	return clone;
}