//
// Created by Temple Tarsha on 1/6/21.
//

#ifndef ATARGET_HPP
#define ATARGET_HPP

#include "ASpell.hpp"

class ASpell;

class ATarget {

protected:
	std::string _type;

public:
	ATarget();
	ATarget(std::string type);
	ATarget(ATarget const &src);
	ATarget & operator=(ATarget const & rhs);
	virtual ~ATarget();

	virtual ATarget * clone() const = 0;

	std::string getType() const;
	void getHitBySpell(ASpell const & spell) const;
};


#endif //ATARGET_HPP
