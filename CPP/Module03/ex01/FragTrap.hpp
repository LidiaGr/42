/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:14:54 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/11 18:14:54 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class FragTrap {

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const & src);
	~FragTrap();

	FragTrap & operator=(const FragTrap & rhs);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	int takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void vaulthunter_dot_exe(std::string const & target);

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
