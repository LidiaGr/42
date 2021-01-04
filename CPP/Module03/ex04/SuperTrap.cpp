/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:14:54 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/11 18:14:54 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap() : FragTrap(), NinjaTrap() {
	std::cout << "SuperTrap Default constructor was called" << std::endl;
	_name = "SuperTrap";
	_HP = 100;
	_maxHP = 100;
	_EP = 120;
	_maxEP = 120;
	_lvl = 1;
	_meleeAD = 60;
	_rangedAD = 20;
	_armor = 5;
}

SuperTrap::SuperTrap(std::string name) : FragTrap(name), NinjaTrap(name) {
	std::cout << "SuperTrap Parametric constructor was called" << std::endl;
	_name = name;
	_HP = 100;
	_maxHP = 100;
	_EP = 120;
	_maxEP = 120;
	_lvl = 1;
	_meleeAD = 60;
	_rangedAD = 20;
	_armor = 5;
}

SuperTrap::SuperTrap(const SuperTrap &src) {
	std::cout << "SuperTrap Copy constructor called" << std::endl;
	*this = src;
}

SuperTrap::~SuperTrap() {
	std::cout << "SuperTrap destructor was called" << std::endl;
}

SuperTrap & SuperTrap::operator=(const SuperTrap &rhs) {
	std::cout << "SuperTrap Assignation operator called" << std::endl;
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