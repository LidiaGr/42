//
// Created by Temple Tarsha on 12/16/20.
//

#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>
#include <string>

class Victim {

protected:
	std::string _name;
	Victim();

public:
	Victim(std::string name);
    virtual ~Victim();
	Victim(const Victim & src);

	Victim & operator=(const Victim & rhs);

	std::string getName() const;

	virtual void getPolymorphed() const;

};

std::ostream & operator<<(std::ostream & o, Victim const & rhs);

#endif
