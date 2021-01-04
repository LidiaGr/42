//
// Created by Temple Tarsha on 12/17/20.
//

#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {

public:

	TacticalMarine();
	~TacticalMarine();
	TacticalMarine(const TacticalMarine & src);

	TacticalMarine & operator=(const TacticalMarine & rhs);

	ISpaceMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif
