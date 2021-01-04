/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:57:47 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/04 18:57:47 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook() {
	_contactsCounter = 0;
}

PhoneBook::~PhoneBook() {}

void 	PhoneBook::addContact() {
	if (_contactsCounter < _contactsAmount)
		_contactBook[_contactsCounter].createContact();
	else
		std::cout << RED << "Phonebook is full " << RESET_COLOR << std::endl;
	_contactsCounter++;
}

void 	PhoneBook::searchContact() const {
	std::string		grids = "|----------|----------|----------|----------|";
	std::string 	index;

	if (!_contactsCounter) {
		std::cout << RED << "There are no contacts is the phonebook yet";
		std::cout << RESET_COLOR << std::endl;
		return;
	}
	std::cout << grids << std::endl;
	std::cout 	<< "|" <<  std::setw(10) << "INDEX" << "|" \
				<< std::setw(10) << "FIRST NAME" << "|" \
				<< std::setw(10) << "LAST NAME" << "|" \
				<< std::setw(10) << "NICKNAME" << "|" << std::endl;
	std::cout << grids << std::endl;
	for(int i = 0; ((i + 1) <= _contactsCounter && (i + 1) <= _contactsAmount); i++) {
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		_contactBook[i].createTableCell();
		std::cout << grids << std::endl;
	}
	std::cout	<< std::endl << YELLOW << "Please enter the index of the desired contact" \
				<< RESET_COLOR << std::endl;
	std::getline(std::cin, index);
	if (index.length() == 1 && (index[0] - '0') <= _contactsCounter && index != "0" && index != "9") {
			_contactBook[(index[0] - '0') - 1].getContact();
	} else {
		std::cout << RED << "There is no such contact's index" << RESET_COLOR << std::endl;
	}
}
