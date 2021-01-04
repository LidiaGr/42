/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/05 21:29:50 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent {
private:
	std::string chosenType;

public:
	ZombieEvent();
	~ZombieEvent();

	void setZombieType(std::string type);
	Zombie	*newZombie(std::string name);
};

#endif
