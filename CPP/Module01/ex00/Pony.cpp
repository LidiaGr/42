/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:18:01 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/05 18:18:01 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name, std::string color, std::string oC)
	: _name(name), _color(color), _outputColor(oC) {
	std::cout	<< _outputColor << "Hello! I'm pony. My name is " << _name
				<< ", I'm " << _color << RESET_COLOR << std::endl;
}

Pony::~Pony() {
	std::cout 	<< _outputColor << "Pony " << _name << " leaves the stage"
				<< RESET_COLOR << std::endl;
}
