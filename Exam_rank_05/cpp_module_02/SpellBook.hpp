//
// Created by Temple Tarsha on 1/6/21.
//

#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <string>
#include "ASpell.hpp"
#include <vector>

class ASpell;

class SpellBook {
private:
	std::vector<ASpell *> _spells;
	SpellBook(SpellBook const &);
	SpellBook & operator=(SpellBook const &);

public:
	SpellBook();
	~SpellBook();

	void learnSpell(ASpell * spell);
	void forgetSpell(std::string const & spellName);
	ASpell* createSpell(std::string const & spell);
};


#endif //SPELLBOOK_HPP
