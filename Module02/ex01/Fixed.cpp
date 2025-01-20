/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:19:03 by cofische          #+#    #+#             */
/*   Updated: 2025/01/20 12:07:41 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fp(0) { 
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int &i_nb) : fp(roundf(((i_nb << fb)))) { 
	std::cout << GREEN << "Int constructor called" << RESET << std::endl;
}

Fixed::Fixed(const float &f_nb) : fp(static_cast<int>(roundf(f_nb * (1 << fb)))){ 
	std::cout << CYAN << "Float constructor called" << RESET << std::endl;
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
	std::cout << GREEN << "getRawfb member function called" << RESET << std::endl;
	return fp;
};
 
void Fixed::setRawBits(int const &raw) {
	fp = raw;
};

float Fixed::toFloat(void) const {
	return static_cast<float>(fp) / (1 << fb);
};

int Fixed::toInt(void) const {
	return fp >> fb;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
};