//
// Created by Lidia Grigoreva on 08/01/2021.
//

#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
protected:
	std::string _type;

public:
	ATarget();
	ATarget(std::string type);
	virtual ~ATarget();

	ATarget(const ATarget &src);
	ATarget & operator=(const ATarget & rhs);

	const std::string &getType() const;

	virtual ATarget * clone() const = 0;

	void getHitBySpell(const ASpell & spell) const;
};


#endif //ATARGET_HPP
