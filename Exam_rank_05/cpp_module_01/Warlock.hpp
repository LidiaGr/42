//
// Created by Temple Tarsha on 1/4/21.
//

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <vector>

class ASpell;
class ATarget;

class Warlock {

private:
	std::string _name;
	std::string _title;
	std::vector<ASpell *> _spells;
	Warlock();
	Warlock( const Warlock & );
	Warlock & operator=( const Warlock & rhs);

public:
	~Warlock();
	Warlock(std::string name, std::string title);

	std::string getName() const;
	std::string getTitle() const;
	void setTitle(std::string info);

	void introduce() const;

	void learnSpell(ASpell *spell);
	void forgetSpell(std::string spellName);
	void launchSpell(std::string spellName, ATarget &target);
};

#endif //WARLOCK_HPP
