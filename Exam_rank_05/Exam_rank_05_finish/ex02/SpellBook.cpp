//
// Created by Lidia Grigoreva on 08/01/2021.
//

#include "SpellBook.hpp"

SpellBook::SpellBook() : _book() {}

SpellBook::~SpellBook() {
	std::vector<ASpell*>::iterator it = _book.begin();
	std::vector<ASpell*>::iterator ite = _book.end();
	while(it != ite){
		delete *it;
		it++;
	}
	_book.clear();
}

void SpellBook::learnSpell(ASpell *spell) {
	if (!spell)
		return;
	std::vector<ASpell*>::iterator it = _book.begin();
	std::vector<ASpell*>::iterator ite = _book.end();
	while(it != ite){
		if((*it)->getName() == spell->getName())
			return;
		it++;
	}
	_book.push_back(spell->clone());
}

void SpellBook::forgetSpell(const std::string &spell) {
	std::vector<ASpell*>::iterator it = _book.begin();
	std::vector<ASpell*>::iterator ite = _book.end();
	while(it != ite){
		if((*it)->getName() == spell) {
			delete *it;
			_book.erase(it);
			return;
		}
		it++;
	}
}

ASpell * SpellBook::createSpell(const std::string &spell) {
	std::vector<ASpell*>::iterator it = _book.begin();
	std::vector<ASpell*>::iterator ite = _book.end();
	while(it != ite){
		if((*it)->getName() == spell) {
			return *it;
		}
		it++;
	}
	return 0;
}