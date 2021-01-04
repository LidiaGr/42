//
// Created by Temple Tarsha on 12/17/20.
//

#ifndef ASSAULTTERMINATOR_HPP
#define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {

public:

	AssaultTerminator();
	~AssaultTerminator();
	AssaultTerminator(const AssaultTerminator & src);

	AssaultTerminator & operator=(const AssaultTerminator & rhs);

	ISpaceMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};


#endif
