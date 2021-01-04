/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:15:15 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/11 18:15:15 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "Something funny. FragTrap Default constructor was called" << std::endl;
	_name = "FragTrap";
	_HP = 100;
	_maxHP = 100;
	_EP = 100;
	_maxEP = 100;
	_lvl = 1;
	_meleeAD = 30;
	_rangedAD = 20;
	_armor = 5;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "Something funny. FragTrap Parametric constructor was called" << std::endl;
	_name = name;
	_HP = 100;
	_maxHP = 100;
	_EP = 100;
	_maxEP = 100;
	_lvl = 1;
	_meleeAD = 30;
	_rangedAD = 20;
	_armor = 5;
}

FragTrap::~FragTrap() {
	std::cout << "Something funny. FragTrap Destructor was called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) {
	std::cout << "Something funny. FragTrap Copy constructor called" << std::endl;
	*this = src;
}

FragTrap & FragTrap::operator=(const FragTrap & rhs) {
	std::cout << "Something funny. FragTrap Assignation operator called" << std::endl;
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

void FragTrap::vaulthunter_dot_exe(const std::string &target) {
	std::string	attacks[5] = 	{
								"funny attack_01",
								"funny attack_02",
								"funny attack_03",
								"funny attack_04",
								"funny attack_05"
								};
	if (_EP < 25) {
		std::cout << "FragTrap " << _name << " has not enough energy for funny attack. Sorry." << std::endl;
		return;
	}
	_EP -= 25;
	static int counter = 4;
	srand(time(nullptr) + counter++);
	int random = rand() % 5;
	std::cout	<< _name << " attacks " << target << " from behind with "
				 << attacks[random] << std::endl;
}
