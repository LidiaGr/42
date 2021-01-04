//
// Created by Temple Tarsha on 12/16/20.
//

#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon {

public:
	PowerFist();
	PowerFist(std::string const &name, int apcost, int damage);
	PowerFist(const PowerFist & src);
	~PowerFist();

	PowerFist & operator=(const PowerFist & rhs);

	virtual void attack() const;
};


#endif
