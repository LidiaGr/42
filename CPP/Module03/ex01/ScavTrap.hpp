/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:14:54 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/11 18:14:54 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class ScavTrap {

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & src);
	~ScavTrap();

	ScavTrap & operator=(const ScavTrap & rhs);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	int takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void challengeNewcomer(std::string const & target);

private:
	std::string		_name;
	unsigned int 	_HP;
	unsigned int 	_maxHP;
	unsigned int 	_EP;
	unsigned int	_maxEP;
	unsigned int 	_lvl;
	unsigned int 	_meleeAD;
	unsigned int 	_rangedAD;
	unsigned int 	_armor;
};

#endif
