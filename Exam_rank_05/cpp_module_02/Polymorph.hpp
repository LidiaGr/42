//
// Created by Temple Tarsha on 1/6/21.
//

#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include "ASpell.hpp"

class Polymorph : public ASpell {

public:
	Polymorph();
	virtual ~Polymorph();
	Polymorph(Polymorph const & src);
	Polymorph & operator=(Polymorph const & rhs);

	virtual ASpell * clone() const;
};

#endif //POLYMORPH_HPP