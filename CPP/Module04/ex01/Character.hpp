//
// Created by Temple Tarsha on 12/16/20.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {

private:
	std::string _name;
	int 		_ap;
	AWeapon		*_weapon;

public:
	Character();
	Character(std::string const & name);
	~Character();
	Character(const Character & src);

	Character & operator=(const Character & rhs);

	void recoverAP();
	void equip(AWeapon*);
	void attack(Enemy*);

	std::string getName() const;
	int getAP() const;
	AWeapon *getWeapon() const;
};

std::ostream & operator<<(std::ostream & o, Character const & rhs);

#endif
