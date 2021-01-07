//
// Created by Temple Tarsha on 1/4/21.
//

#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(const Warlock &) {}

Warlock & Warlock::operator=(const Warlock &) {
//	if (this != &rhs) {
//		this->_name = rhs._name;
//		this->_title = rhs._title;
//		for(size_t i = 0; i < _spellBook.size(); i++) {
//			this->_spells[i] = rhs._spells[i];
//		}
//	}
	return *this;
}

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
	_spellBook = new SpellBook();
}

Warlock::~Warlock() {
	std::cout << this->getName() << ": My job here is done!" << std::endl;
	delete _spellBook;
}

std::string Warlock::getName() const {
	return this->_name;
}

std::string Warlock::getTitle() const {
	return this->_title;
}

void Warlock::setTitle(std::string info) {
	this->_title = info;
}

void Warlock::introduce() const {
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell) {
	_spellBook->learnSpell(spell);

}

void Warlock::forgetSpell(std::string spellName) {
	_spellBook->forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, ATarget &target) {
	_spellBook->createSpell(spellName)->launch(target);
}
