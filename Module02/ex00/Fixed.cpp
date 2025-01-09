/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:19:03 by cofische          #+#    #+#             */
/*   Updated: 2025/01/09 15:33:51 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fp(0) {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
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