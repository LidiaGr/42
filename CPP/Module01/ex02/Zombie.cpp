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

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) { };

Zombie::~Zombie() {};

void 	Zombie::announce() {
	if (this->_name == "John Snow")
		std::cout << "<" << _name << " (" << _type << ") > Braiiiiiiinnnssss... Winter is coming" << std::endl;
	else
		std::cout << "<" << _name << " (" << _type << ") > Braiiiiiiinnnssss..." << std::endl;
}
