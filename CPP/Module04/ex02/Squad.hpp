//
// Created by Temple Tarsha on 12/17/20.
//

#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad {

private:
	int		_unitsCount;
	ISpaceMarine **_units;

public:
	Squad();
	~Squad();
	Squad(const Squad & src);

	Squad & operator=(const Squad & rhs);

	int getCount() const;
	ISpaceMarine* getUnit(int) const;
	int push(ISpaceMarine*);

};

#endif
