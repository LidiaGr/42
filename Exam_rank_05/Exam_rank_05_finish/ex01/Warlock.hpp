//
// Created by Lidia Grigoreva on 08/01/2021.
//

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <vector>

class Warlock {
private:
	std::string _name;
	std::string _title;
	std::vector<ASpell*> _spells;
	Warlock() {};
	Warlock(Warlock const &) {};
	Warlock & operator=(Warlock const &) {return *this;};


public:
	Warlock(std::string name, std::string title);
	~Warlock();

	std::string const & getName() const;
	std::string const & getTitle() const;
	void setTitle(std::string const & title);

	void introduce() const;

	void learnSpell(ASpell *spell);
	void forgetSpell(std::string name);
	void launchSpell(std::string spell, ATarget & target);
};


#endif //WARLOCK_HPP
