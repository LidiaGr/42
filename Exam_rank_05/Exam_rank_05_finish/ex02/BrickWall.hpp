//
// Created by Lidia Grigoreva on 08/01/2021.
//

#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "ATarget.hpp"

class BrickWall : public ATarget {
public:
	BrickWall();
	virtual ~BrickWall();

	virtual ATarget * clone() const;
};

#endif //BRICKWALL_HPP
