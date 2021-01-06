//
// Created by Temple Tarsha on 1/4/21.
//

#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(const Warlock &) {}

Warlock & Warlock::operator=(const Warlock & rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_title = rhs._title;
		for(size_t i = 0; i < _spells.size(); i++) {
			this->_spells[i] = rhs._spells[i];
		}

	}
	return *this;
}

Warlock::~Warlock() {
	std::cout << this->getName() << ": My job here is done!" << std::endl;
	for (size_t i = 0; i < _spells.size(); i++) {
		delete _spells[i];
	}
	_spells.clear();
}

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
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

void Warlock::forgetSpell(std::string spellName) {
	std::vector<ASpell *>::iterator it = _spells.begin();
	std::vector<ASpell *>::iterator ite = _spells.end();
	for(; it != ite; it++) {
		if ((*it)->getName().compare(spellName) == 0){
			_spells.erase(it);
			return;
		}
	}
}

void Warlock::launchSpell(std::string spellName, ATarget &target) {
	std::vector<ASpell *>::iterator it = _spells.begin();
	std::vector<ASpell *>::iterator ite = _spells.end();
	for (; it != ite; it++) {
		if ((*it)->getName().compare(spellName) == 0) {
			(*it)->launch(target);
			break;
		}
	}
}
