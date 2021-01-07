//
// Created by Temple Tarsha on 1/6/21.
//

#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "ATarget.hpp"

class BrickWall : public ATarget {

public:
	BrickWall();
	~BrickWall();
	BrickWall(BrickWall const & src);
	BrickWall & operator=(BrickWall const & rhs);

	virtual ATarget * clone() const;
};

#endif //BRICKWALL_HPP