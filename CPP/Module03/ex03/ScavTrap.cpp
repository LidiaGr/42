/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:15:15 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/11 18:15:15 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "Funny ScavTrap Default constructor was called" << std::endl;
	_name = "ScavTrap";
	_HP = 100;
	_maxHP = 100;
	_EP = 50;
	_maxEP = 50;
	_lvl = 1;
	_meleeAD = 20;
	_rangedAD = 15;
	_armor = 3;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "Funny ScavTrap Parametric constructor was called" << std::endl;
	_name = name;
	_HP = 100;
	_maxHP = 100;
	_EP = 50;
	_maxEP = 50;
	_lvl = 1;
	_meleeAD = 20;
	_rangedAD = 15;
	_armor = 3;
}

ScavTrap::~ScavTrap() {
	std::cout << "Funny ScavTrap Destructor was called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) {
	std::cout << "Funny ScavTrap Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & rhs) {
	std::cout << "Funny ScavTrap Assignation operator called" << std::endl;
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

void ScavTrap::challengeNewcomer(const std::string &target) {
	std::string	attacks[5] = 	{
								"funny challenge_01",
								"funny challenge_02",
								"funny challenge_03",
								"funny challenge_04",
								"funny challenge_05"
								};
	if (_EP < 25) {
		std::cout << "ScavTrap " << _name << " has not enough energy for funny challenge. Sorry." << std::endl;
		return;
	}
	_EP -= 25;
	static int counter = 1;
	srand(time(nullptr) + counter++);
	int random = rand() % 5;
	std::cout << _name << " challenged " << target << " at the door with " << attacks[random] << std::endl;
}
