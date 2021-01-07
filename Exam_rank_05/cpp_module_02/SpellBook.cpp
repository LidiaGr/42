//
// Created by Temple Tarsha on 1/6/21.
//

#include "SpellBook.hpp"

SpellBook::SpellBook() : _spells() {}

SpellBook::~SpellBook() {
	std::vector<ASpell *>::iterator it = _spells.begin();
	std::vector<ASpell *>::iterator ite = _spells.end();
	for (; it != ite; it++) {
		delete *it;
	}
	_spells.clear();
}

SpellBook::SpellBook(const SpellBook &) {}

SpellBook & SpellBook::operator=(const SpellBook &) {return *this;}

void SpellBook::learnSpell(ASpell *spell) {
	if (!spell)
		return;
	std::vector<ASpell *>::iterator it = _spells.begin();
	std::vector<ASpell *>::iterator ite = _spells.end();
	for(; it != ite; it++) {
		if ((*it)->getName().compare(spell->getName()) == 0) {
			return;
		}
	}
	_spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(const std::string &spellName) {
	std::vector<ASpell *>::iterator it = _spells.begin();
	std::vector<ASpell *>::iterator ite = _spells.end();
	for(; it != ite; it++) {
		if ((*it)->getName().compare(spellName) == 0) {
			delete *it;
			_spells.erase(it);
			return;
		}
	}
}

ASpell * SpellBook::createSpell(const std::string &spell) {
	std::vector<ASpell *>::iterator it = _spells.begin();
	std::vector<ASpell *>::iterator ite = _spells.end();
	for (; it != ite; it++) {
		if ((*it)->getName().compare(spell) == 0) {
			return (*it);
		}
	}
	return (0);
}
