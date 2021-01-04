//
// Created by Temple Tarsha on 12/18/20.
//

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {

public:
	Cure();
	Cure(const Cure & src);
	~Cure();

	Cure & operator=(const Cure & rhs);

	Cure* clone() const;
	void use(ICharacter& target);
};

#endif
