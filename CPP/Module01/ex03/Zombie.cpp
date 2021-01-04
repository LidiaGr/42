/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:11:19 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/05 21:11:19 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::~Zombie() {};

void 	Zombie::setName(std::string name) {
	this->_name = name;
}

void 	Zombie::announce() {
	if (this->_name == "John Snow")
		std::cout << "<" << _name << "> Braiiiiiiinnnssss... of King in the North" << std::endl;
	else
		std::cout << "<" << _name << "> Braiiiiiiinnnssss..." << std::endl;
}
