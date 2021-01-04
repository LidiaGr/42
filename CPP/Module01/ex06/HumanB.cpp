/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:23:00 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/07 21:23:00 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::~HumanB() {}

void 	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void 	HumanB::attack() {
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}
