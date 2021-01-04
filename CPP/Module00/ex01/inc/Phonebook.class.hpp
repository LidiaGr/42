/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:44:58 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/04 18:44:58 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

class 	PhoneBook {
private:
	int 				_contactsCounter;
	int static const	_contactsAmount = 8;
	Contact				_contactBook[_contactsAmount];

public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContact() const;
};

#endif
