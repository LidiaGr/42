/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:18:13 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/05 18:18:13 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheStack(std::string name, std::string color, std::string oC) {
	Pony	pony1(name, color, oC);
	std::cout << oC << "I'm singing. My memory was allocated on the STACK" << RESET_COLOR << std::endl;
};

void	ponyOnTheHeap(std::string name, std::string color, std::string oC) {
	Pony	*pony2 = new Pony(name, color, oC);

	std::cout << oC << "I'm dancing. My memory was allocated on the HEAP" << RESET_COLOR << std::endl;
	delete pony2;
};

int main() {
	ponyOnTheStack("Lisa", "pink", PINK);
	ponyOnTheHeap("Jack", "black", YELLOW);
	return 0;
}
