//
// Created by Lidia Grigoreva on 08/01/2021.
//

#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {
	_name = "Fwoosh";
	_effects = "fwooshed";
}

Fwoosh::~Fwoosh() {}

ASpell * Fwoosh::clone() const {
	return (new Fwoosh());
}

