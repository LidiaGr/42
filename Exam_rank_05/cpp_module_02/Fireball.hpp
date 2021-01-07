//
// Created by Temple Tarsha on 1/6/21.
//

#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include "ASpell.hpp"

class Fireball : public ASpell {

public:
	Fireball();
	virtual ~Fireball();
	Fireball(Fireball const & src);
	Fireball & operator=(Fireball const & rhs);

	virtual ASpell * clone() const;
};


#endif //FIREBALL_HPP
