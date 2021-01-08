//
// Created by Lidia Grigoreva on 08/01/2021.
//

#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title) {
	_book = new SpellBook();
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
	delete _book;
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
	_book->learnSpell(spell);
}

void Warlock::forgetSpell(std::string name) {
	_book->forgetSpell(name);
}

void Warlock::launchSpell(std::string spell, ATarget & target) {
	ASpell * tmp = _book->createSpell(spell);
	if (tmp)
		tmp->launch(target);
}

