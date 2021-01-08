//
// Created by Lidia Grigoreva on 08/01/2021.
//

#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {
protected:
	std::string _name;
	std::string _effects;

public:
	ASpell();
	ASpell(std::string name, std::string effects);
	virtual ~ASpell();

	ASpell(const ASpell &src);
	ASpell & operator=(const ASpell & rhs);

	const std::string &getName() const;
	const std::string &getEffects() const;

	virtual ASpell * clone() const = 0;

	void launch(const ATarget & target);
};


#endif //ASPELL_HPP
