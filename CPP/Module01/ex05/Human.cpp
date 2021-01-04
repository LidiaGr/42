/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 03:43:19 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/07 03:43:19 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human() {}

Human::~Human() {}

const Brain &Human::getBrain() {
	return (this->_pinky);
}

std::string Human::identify() {
	return (_pinky.identify());
}