//
// Created by Temple Tarsha on 12/16/20.
//

#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <iostream>
#include <string>

class AWeapon {

protected:
	std::string _name;
	int 		_apcost;
	int 		_damage;

public:
	AWeapon();
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(const AWeapon & src);
	~AWeapon();

	AWeapon & operator=(const AWeapon & rhs);

	std::string getName() const;
	int getAPCost() const;
	int getDamage() const;

	virtual void attack() const = 0;
};

#endif
