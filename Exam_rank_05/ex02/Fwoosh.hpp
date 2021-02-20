//
// Created by Lidia Grigoreva on 08/01/2021.
//

#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include "ASpell.hpp"

class Fwoosh : public ASpell {
public:
	Fwoosh();
	virtual ~Fwoosh();

	virtual ASpell * clone() const;
};


#endif //FWOOSH_HPP
