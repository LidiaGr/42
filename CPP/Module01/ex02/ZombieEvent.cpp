/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:45:20 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/05 21:45:20 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() { }

ZombieEvent::~ZombieEvent() { }

void 	ZombieEvent::setZombieType(std::string type) {
	chosenType = type;
}

Zombie	*ZombieEvent::newZombie(std::string name) {
	if (name[0] == 'J')
		setZombieType("King in the North");
	else if (name == "Ramsi")
		setZombieType("Bolton");
	else if (name == "Tirion" || name == "Sercei")
		setZombieType("Lannister");
	else if (name == "Teon")
		setZombieType("Grayjoy");
	else
		setZombieType("Stark");
	Zombie *clone = new Zombie(name, chosenType);
	clone->announce();
	return (clone);
};
