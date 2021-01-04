/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:18:47 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/05 18:18:47 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
#define PONY_HPP

#include <string>
#include <iostream>

#define YELLOW "\033[33m"
#define PINK "\033[35m"
#define RESET_COLOR "\033[0m"

class Pony{
private:
	std::string _name;
	std::string _color;
	std::string _outputColor;

public:
	Pony(std::string name, std::string color, std::string oC);
	~Pony();
};

#endif
