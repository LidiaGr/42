/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:11:28 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/04 15:11:28 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void 	Contact::createContact() {
	_params[0] = "first name: ";
	_params[1] = "last name: ";
	_params[2] = "nickname: ";
	_params[3] = "login: ";
	_params[4] = "postal address: ";
	_params[5] = "email address: ";
	_params[6] = "phone number: ";
	_params[7] = "birthday date: ";
	_params[8] = "favorite meal: ";
	_params[9] = "underwear color: ";
	_params[10] = "darkest secret: ";

	for(int i = 0; i < _nbOfFields; i++) {
		std::cout << YELLOW << "Please enter " << _params[i] << RESET_COLOR;
		std::getline(std::cin, _data[i]);
		while (!(_data[i].length()) && (i < 3 || i == 6)) {
			std::cout << YELLOW << "Please enter " << _params[i] << RESET_COLOR;
			std::getline(std::cin, _data[i]);
		}
	}
}

void 	Contact::createTableCell() const {
	for(int i = 0; i < 3; i++) {
		if (_data[i].length() <= 10)
			std::cout << std::setw(10) << _data[i] << "|";
		else
			std::cout << _data[i].substr(0, 9) << ".|" ;
	}
	std::cout << std::endl;
}

void	Contact::getContact() const {
	for(int i = 0; i < _nbOfFields; i++) {
		std::cout << Contact::_params[i] << Contact::_data[i] << std::endl;
	}
}