//
// Created by Temple Tarsha on 12/16/20.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <string>

class Enemy {

protected:
	int	_hp;
	std::string _type;

public:
	Enemy();
	Enemy(int hp, std::string const & type);
	Enemy(const Enemy & src);
	virtual ~Enemy();

	Enemy & operator=(const Enemy & rhs);

	std::string getType() const;
	int getHP() const;
	virtual void takeDamage(int);
};


#endif
