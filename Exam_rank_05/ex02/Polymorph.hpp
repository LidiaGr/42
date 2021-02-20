//
// Created by Lidia Grigoreva on 08/01/2021.
//

#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include "ASpell.hpp"

class Polymorph : public ASpell {
public:
	Polymorph();
	virtual ~Polymorph();

	virtual ASpell * clone() const;
};

#endif //POLYMORPH_HPP
