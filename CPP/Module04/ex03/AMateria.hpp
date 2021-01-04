//
// Created by Temple Tarsha on 12/18/20.
//

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {

protected:
	unsigned int _xp;
	std::string	_type;

public:
	AMateria(std::string const & type);
	AMateria();
	AMateria(const AMateria & src);
	virtual ~AMateria();

	AMateria & operator=(const AMateria & rhs);

//	void setXp();

	std::string const & getType() const; //Returns the materia type
	unsigned int getXP() const; //Returns the Materia's XP

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

};


#endif
