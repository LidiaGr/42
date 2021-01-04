/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:14:54 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/11 18:14:54 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :	_name("Default"), _HP(0), _maxHP(0),
						_EP(0), _maxEP(0), _lvl(0), _meleeAD(0),
						_rangedAD(0), _armor(0){
	std::cout << "Parent ClapTrap Default constructor was called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :	_name(name), _HP(0), _maxHP(0),
										_EP(0), _maxEP(0), _lvl(0), _meleeAD(0),
										_rangedAD(0), _armor(0)
{
	std::cout << "Parent ClapTrap Parametric constructor was called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Parent ClapTrap destructor was called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "Parent ClapTrap Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap & ClapTrap::operator=(const ClapTrap & rhs) {
	std::cout << "Parent ClapTrap Assignation operator called" << std::endl;
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

void ClapTrap::rangedAttack(const std::string &target) {
	std::cout << _name << "'s EP is " << _EP
			  << " and HP is "	<< _HP << std::endl;
	if (_EP >= _meleeAD && (_EP - _rangedAD) >= 0 && _HP > 0) {
		_EP -= _rangedAD;
	} else {
		std::cout << _name << " has not enough energy for attack." << std::endl;
		return;
	}
	std::cout	 << _name << " attacks " << target
				  << " at range, causing " << _rangedAD << " points of damage!" << std::endl;
}

void ClapTrap::meleeAttack(const std::string &target) {
	std::cout << _name << "'s EP is " << _EP
			  << " and HP is "	<< _HP << std::endl;
	if (_EP >= _meleeAD && (_EP - _meleeAD) >= 0 && _HP > 0) {
		_EP -= _meleeAD;
	} else {
		std::cout << _name << " has not enough energy for attack." << std::endl;
		return;
	}
	std::cout	<< _name << " attacks " << target
				 << " at melee, causing " << _meleeAD << " points of damage!" << std::endl;
}

int ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "takeDamage function was called." << std::endl;
	if ((_HP + _armor) >= amount && (_HP + _armor - amount) >= 0) {
		_HP -= (amount - _armor);
		std::cout << "Actual HP of " << _name << " after attack is " << _HP << "." << std::endl;
	} else {
		_HP = 0;
		std::cout << _name << " is offline." << std::endl;
	}
	return 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "beRepaired function was called." << std::endl;
	std::cout << _name << "'s HP before repair is " << _HP << std::endl;
	if (_HP == _maxHP)
		std::cout << _name << " HP is maximum." << std::endl;
	else if ((_HP + amount) <= _maxHP) {
		_HP += amount;
		std::cout << _name << "'s HP after repair is " << _HP << std::endl;
	}
	else
		std::cout << _name << " HP cannot be more than maximum." << std::endl;

	std::cout << _name << "'s EP before repair is " << _EP << std::endl;
	if (_EP == _maxEP)
		std::cout << _name << " EP is maximum." << std::endl;
	else if ((_EP + amount) <= _maxEP) {
		_EP += amount;
		std::cout << _name << "'s EP after repair is " << _EP << std::endl;
	}
	else
		std::cout << _name << " EP cannot be more than maximum." << std::endl;
}

std::string ClapTrap::getName() {
	return this->_name;
}

void ClapTrap::describeYourself() {
	std::cout << std::setw(8) << "name: " << _name << std::endl;
	std::cout << std::setw(8) << "HP: " << _HP << std::endl;
	std::cout << std::setw(8) << "maxHP: " << _maxHP << std::endl;
	std::cout << std::setw(8) << "EP: " << _EP << std::endl;
	std::cout << std::setw(8) << "maxEP: " << _maxEP << std::endl;
	std::cout << std::setw(8) << "lvl: " << _lvl << std::endl;
	std::cout << std::setw(8) << "melee: " << _meleeAD << std::endl;
	std::cout << std::setw(8) << "ranged: " << _rangedAD << std::endl;
	std::cout << std::setw(8) << "armor: " << _armor << std::endl;
}
