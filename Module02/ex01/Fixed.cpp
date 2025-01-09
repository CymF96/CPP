/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:19:03 by cofische          #+#    #+#             */
/*   Updated: 2025/01/09 17:02:11 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fp(0) { 
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int &i_nb) { 
	std::cout << YELLOW << "Int constructor called" << RESET << std::endl;
	fp = i_nb << bits;
}

Fixed::Fixed(const float &f_nb) { 
	std::cout << YELLOW << "Float constructor called" << RESET << std::endl;
	fp = static_cast<int>(f_nb * (1 << bits));
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other) : fp(other.fp) {
	std::cout << MAGENTA << "Copy constructor called" << RESET << std::endl;
};

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << BLUE << "Copy Assignment operator called" << RESET << std::endl;
	if (this != &other) {
		fp = other.fp;
	}
	return *this;
};

int Fixed::getRawBits(void) const {
	std::cout << GREEN << "getRawBits member function called" << RESET << std::endl;
	return fp;
};
 
void Fixed::setRawBits(int const &raw) {
	fp = raw;
};

float Fixed::toFloat(void) {
	fp = static_cast<float>(fp / (1 << bits));
	return fp;
};

int Fixed::toInt(void) {
	fp = fp >> bits;
	return fp;
};