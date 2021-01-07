//
// Created by Temple Tarsha on 1/6/21.
//

#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <string>
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
	ASpell(ASpell const &src);
	ASpell & operator=(ASpell const & rhs);
	virtual ~ASpell();

	std::string getName() const;
	std::string getEffects() const;

	virtual ASpell * clone() const = 0;

	void launch(ATarget const & target);
};


#endif //ASPELL_HPP
