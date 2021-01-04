//
// Created by Temple Tarsha on 12/18/20.
//

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {

public:
	Ice();
	Ice(const Ice & src);
	~Ice();

	Ice & operator=(const Ice & rhs);

	Ice* clone() const;
	void use(ICharacter& target);
};

#endif
