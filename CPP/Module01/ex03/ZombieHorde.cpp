/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:38:08 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/06 20:38:08 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <cstdlib>
#include <ctime>

std::string		randomChump() {
	static int	counter;
	int 		rName;

	std::string randomNames[8] =	{
			"John Snow", "Teon",
			"Sansa", "Ramsi", "Aria",
			"Tirion", "Hodor", "Bran"
	};
	srand (time(0) + counter);
	counter++;
	rName = rand() % 8;
	return (randomNames[rName]);
}

ZombieHorde::ZombieHorde(int N) {
	this->Horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		Horde[i].setName(randomChump());
		Horde[i].announce();
	}
}

ZombieHorde::~ZombieHorde() {
	std::cout << "All Zombies were burned" << std::endl;
	delete [] Horde;
}
