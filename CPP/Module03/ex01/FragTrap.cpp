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

FragTrap::FragTrap() {
	std::cout << "Something funny. Default constructor was called" << std::endl;
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

FragTrap::FragTrap(std::string name) : _name(name) {
	std::cout << "Something funny. Parametric constructor was called" << std::endl;
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
	std::cout << "Something funny. Destructor was called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) {
	std::cout << "Something funny. Copy constructor called" << std::endl;
	*this = src;
}

FragTrap & FragTrap::operator=(const FragTrap & rhs) {
	std::cout << "Something funny. Assignation operator called" << std::endl;
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

void FragTrap::rangedAttack(const std::string &target) {
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

void FragTrap::meleeAttack(const std::string &target) {
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

int FragTrap::takeDamage(unsigned int amount) {
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

void FragTrap::beRepaired(unsigned int amount) {
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

void FragTrap::vaulthunter_dot_exe(const std::string &target) {
	std::string	attacks[5] = 	{
								"funny attack_01",
								"funny attack_02",
								"funny attack_03",
								"funny attack_04",
								"funny attack_05"
								};
	std::cout << _name << "'s EP is " << _EP << std::endl;
	if (_EP < 25) {
		std::cout << _name << " has not enough energy for funny attack. Sorry." << std::endl;
		return;
	}
	_EP -= 25;
	static int	counter = 1;
	srand(time(nullptr) + counter++);
	int random = rand() % 5;
	std::cout	<< _name << " attacks " << target << " from behind with "
				 << attacks[random] << std::endl;
}
