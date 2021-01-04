//
// Created by Temple Tarsha on 12/16/20.
//

#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

public:
	PlasmaRifle();
	PlasmaRifle(std::string const &name, int apcost, int damage);
	PlasmaRifle(const PlasmaRifle & src);
	~PlasmaRifle();

	PlasmaRifle & operator=(const PlasmaRifle & rhs);

	virtual void attack() const;
};


#endif
