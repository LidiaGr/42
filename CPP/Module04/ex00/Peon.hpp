//
// Created by Temple Tarsha on 12/16/20.
//

#ifndef PEON_HPP
#define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim {

private:
	Peon();

public:
	Peon(std::string name);
	virtual ~Peon();
	Peon(const Peon & src);

	Peon & operator=(const Peon * rhs);
	void getPolymorphed() const;
};


#endif
