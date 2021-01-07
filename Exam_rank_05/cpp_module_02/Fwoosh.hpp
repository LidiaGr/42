//
// Created by Temple Tarsha on 1/6/21.
//

#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include "ASpell.hpp"

class Fwoosh : public ASpell {

public:
	Fwoosh();
	~Fwoosh();
	Fwoosh(Fwoosh const & src);
	Fwoosh & operator=(Fwoosh const & rhs);

	virtual ASpell * clone() const;
};


#endif //FWOOSH_HPP
