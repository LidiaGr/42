//
// Created by Temple Tarsha on 12/16/20.
//

#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy {

public:
	SuperMutant();
	SuperMutant(const SuperMutant & src);
	~SuperMutant();

	SuperMutant & operator=(const SuperMutant & rhs);

	void takeDamage(int);
};

#endif
