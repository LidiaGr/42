/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:12:10 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/04 15:12:10 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

class	Contact {
private:
	int static const	_nbOfFields = 11;
	std::string			_params[_nbOfFields];
	std::string			_data[_nbOfFields];

public:
	Contact();
	~Contact();

	void createContact();
	void createTableCell(void) const;
	void getContact(void) const;
};

#endif
