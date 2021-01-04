/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:11:25 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/09 19:11:25 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->fixedPointValue = 0;
}

Fixed & Fixed::operator=(const Fixed & rhs) {
	std::cout << "Assignation operator called" << std::endl;
	this->fixedPointValue = rhs.getRawBits();

	return *this;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int nb) {
	fixedPointValue = (nb << nbOfFractionalBits);
}

Fixed::Fixed(const float nb) {
	fixedPointValue = roundf(nb * (1 << nbOfFractionalBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointValue;
}

void Fixed::setRawBits(const int raw) {
	this->fixedPointValue = raw;
}

int Fixed::toInt() const {
	return (fixedPointValue >> nbOfFractionalBits);
}

float Fixed::toFloat() const {
	return (float(fixedPointValue) / (1 << nbOfFractionalBits));
}

std::ostream & operator<<(std::ostream & o, const Fixed & rhs) {
	o << rhs.toFloat();
	return o;
}