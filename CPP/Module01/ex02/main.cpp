/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:07:13 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/06 18:07:13 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include <cstdlib>
#include <ctime>

Zombie *randomChump(ZombieEvent Event) {
	Zombie		*zoo;
	static int	counter;
	int 		rName;

	std::string randomNames[8] =	{
									"John Snow", "Teon",
									"Sansa", "Ramsi", "Aria",
									"Tirion", "Sercei", "Bran"
									};
	srand (time(nullptr) + counter);
	counter++;
	rName = rand() % 8;
	zoo = Event.newZombie(randomNames[rName]);
	return (zoo);
}

int 	main(void) {
	ZombieEvent Event;
	int 		nb = 7;
	Zombie		*zoo[nb];

	for(int i = 0; i < nb; i++)
		zoo[i] = randomChump(Event);
	for(int i = 0; i < nb; i++)
		delete zoo[i];
	return 0;
}
