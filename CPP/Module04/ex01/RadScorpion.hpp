//
// Created by Temple Tarsha on 12/16/20.
//

#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy {

public:
	RadScorpion();
	RadScorpion(const RadScorpion & src);
	~RadScorpion();

	RadScorpion & operator=(const RadScorpion & rhs);
};


#endif
