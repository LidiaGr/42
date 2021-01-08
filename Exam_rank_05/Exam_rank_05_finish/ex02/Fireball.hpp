//
// Created by Lidia Grigoreva on 08/01/2021.
//

#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include "ASpell.hpp"

class Fireball : public ASpell {
public:
	Fireball();
	virtual ~Fireball();

	virtual ASpell * clone() const;
};


#endif //FIREBALL_HPP
