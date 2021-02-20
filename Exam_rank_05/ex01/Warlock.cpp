//
// Created by Lidia Grigoreva on 08/01/2021.
//

#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title), _spells() {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
	std::vector<ASpell*>::iterator it = _spells.begin();
	std::vector<ASpell*>::iterator ite = _spells.end();
	while(it != ite){
		delete *it;
		it++;
	}
	_spells.clear();
}

const std::string & Warlock::getName() const {
	return this->_name;
}

const std::string & Warlock::getTitle() const { return this->_title;}

void Warlock::setTitle(const std::string &title) {
	_title = title;
}

void Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell) {
	if (!spell)
		return;
	std::vector<ASpell*>::iterator it = _spells.begin();
	std::vector<ASpell*>::iterator ite = _spells.end();
	while(it != ite){
		if((*it)->getName() == spell->getName())
			return;
		it++;
	}
	_spells.push_back(spell->clone());
}

void Warlock::forgetSpell(std::string name) {
	std::vector<ASpell*>::iterator it = _spells.begin();
	std::vector<ASpell*>::iterator ite = _spells.end();
	while(it != ite){
		if((*it)->getName() == name) {
			delete *it;
			_spells.erase(it);
			return;
		}
		it++;
	}
}

void Warlock::launchSpell(std::string spell, ATarget & target) {
	std::vector<ASpell*>::iterator it = _spells.begin();
	std::vector<ASpell*>::iterator ite = _spells.end();
	while(it != ite){
		if((*it)->getName() == spell) {
			(*it)->launch(target);
			return;
		}
		it++;
	}
}

