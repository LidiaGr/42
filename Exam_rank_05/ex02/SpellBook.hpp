//
// Created by Lidia Grigoreva on 08/01/2021.
//

#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <vector>

class SpellBook {
private:
	std::vector<ASpell*> _book;
	SpellBook(SpellBook const &) {};
	SpellBook & operator=(SpellBook const &) {return *this;}

public:
	SpellBook();
	virtual ~SpellBook();

	void learnSpell(ASpell * spell);
	void forgetSpell(std::string const & spell);
	ASpell* createSpell(std::string const & spell);
};


#endif //SPELLBOOK_HPP
