/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:14:54 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/11 18:14:54 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define YELLOW "\033[33m"
#define RED "\033[31m"
#define RESET_COLOR "\033[0m"

class ClapTrap {

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & src);
	~ClapTrap();

	ClapTrap & operator=(const ClapTrap & rhs);

	std::string getName();

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	int takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void describeYourself();

protected:
	std::string		_name;
	unsigned int 	_HP;
	unsigned int	_maxHP;
	unsigned int 	_EP;
	unsigned int	_maxEP;
	unsigned int 	_lvl;
	unsigned int	_meleeAD;
	unsigned int	_rangedAD;
	unsigned int	_armor;
};



#endif
