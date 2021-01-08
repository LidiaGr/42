//
// Created by Lidia Grigoreva on 08/01/2021.
//

#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {}

Fireball::~Fireball() {}

ASpell * Fireball::clone() const {
	return (new Fireball());
}