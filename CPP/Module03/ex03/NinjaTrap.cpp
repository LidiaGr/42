/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:14:54 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/11 18:14:54 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() : ClapTrap() {
	std::cout << "NinjaTrap Default constructor was called" << std::endl;
	_name = "NinjaTrap";
	_HP = 60;
	_maxHP = 60;
	_EP = 120;
	_maxEP = 120;
	_lvl = 1;
	_meleeAD = 60;
	_rangedAD = 5;
	_armor = 0;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name) {
	std::cout << "NinjaTrap Parametric constructor was called" << std::endl;
	_name = name;
	_HP = 60;
	_maxHP = 60;
	_EP = 120;
	_maxEP = 120;
	_lvl = 1;
	_meleeAD = 60;
	_rangedAD = 5;
	_armor = 0;
}

NinjaTrap::~NinjaTrap() {
	std::cout << "NinjaTrap Destructor was called" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &src) {
	std::cout << "NinjaTrap Copy constructor called" << std::endl;
	*this = src;
}

NinjaTrap & NinjaTrap::operator=(const NinjaTrap &rhs) {
	std::cout << "NinjaTrap Assignation operator called" << std::endl;
	this->_name = rhs._name;
	this->_HP = rhs._HP;
	this->_maxHP = rhs._maxHP;
	this->_EP = rhs._EP;
	this->_maxEP = rhs._maxEP;
	this->_lvl = rhs._lvl;
	this->_meleeAD = rhs._meleeAD;
	this->_rangedAD = rhs._rangedAD;
	this->_armor = rhs._armor;
	return *this;
}

void NinjaTrap::ninjaShoebox(FragTrap &target) {
	std::cout	<< "NinjaTrap " << _name << " attacked FragTrap "
				 << target.getName() << ", causing 25 points of damage!" << std::endl;
	target.takeDamage(25);
}

void NinjaTrap::ninjaShoebox(ScavTrap &target) {
	std::cout	<< "NinjaTrap " << _name << " attacked ScavTrap "
				 << target.getName() << ", causing 25 points of damage!" << std::endl;
	target.takeDamage(25);
}

void NinjaTrap::ninjaShoebox(NinjaTrap &target) {
	std::cout	<< "NinjaTrap " << _name << " attacked NinjaTrap "
				 << target.getName() << ", causing 25 points of damage!" << std::endl;
	target.takeDamage(25);
}

