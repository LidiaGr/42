/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:31:18 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/04 19:31:18 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int 	main()
{
	PhoneBook	newBook;

	std::string		input;

	std::cout 	<< AQUA << "Please enter ADD or SEARCH to handle contacts, " \
				<< "or enter EXIT to leave the Phonebook." \
				<< RESET_COLOR << std::endl;
	std::getline(std::cin, input);
	while (input != "EXIT")
	{
		if (input == "ADD")
			newBook.addContact();
		else if (input == "SEARCH")
			newBook.searchContact();
		std::cout	<< std::endl << AQUA << "Please enter a command" \
					<< RESET_COLOR << std::endl;
		std::getline(std::cin, input);
	}
	return 0;
}
