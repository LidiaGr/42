//
// Created by Lidia Grigoreva on 08/01/2021.
//

#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {
	_type = "Target Practice Dummy";
}

Dummy::~Dummy() {}

ATarget * Dummy::clone() const {
	return (new Dummy());
}