/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:19:03 by cofische          #+#    #+#             */
/*   Updated: 2025/01/11 11:35:38 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp" 

Fixed::Fixed() : fp(0) { 
	// std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int &i_nb) : fp(i_nb << bits) { 
	// std::cout << YELLOW << "Int constructor called" << RESET << std::endl;
}

Fixed::Fixed(const float &f_nb) : fp(static_cast<int>(f_nb * (1 << bits))){ 
	// std::cout << YELLOW << "Float constructor called" << RESET << std::endl;
}

Fixed::~Fixed() {
	// std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other) : fp(other.fp) {
	// std::cout << MAGENTA << "Copy constructor called" << RESET << std::endl;
};

/*OPERATOR OVERLOADED*/

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << BLUE << "Copy Assignment operator called" << RESET << std::endl;
	if (this != &other) {
		fp = other.fp;
	}
	return *this;
};

	/*COMPARISON OPERATORS*/
bool Fixed::operator<(const Fixed &other) const {
	return this->fp < other.fp;
};

bool Fixed::operator>(const Fixed &other) const {
	return this->fp > other.fp;
};

bool Fixed::operator<=(const Fixed &other) const {
	return this->fp <= other.fp;
};

bool Fixed::operator>=(const Fixed &other) const {
	return this->fp >= other.fp;
};

bool Fixed::operator==(const Fixed &other) const {
	return this->fp == other.fp;
};

bool Fixed::operator!=(const Fixed &other) const {
	return this->fp != other.fp;
};

	/*ARITHMETIC OPERATOR*/
Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.fp = this->fp + other.fp;
	return result;
};

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.fp = this->fp - other.fp;
	return result;
};

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.fp = this->fp * other.fp >> bits;
	return result;
};

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	result.fp = (this->fp << bits) / other.fp;
	return result;	
};

	/*INCREMENT/DECREMENT OPERATOR*/
Fixed Fixed::operator++() {
	this->fp += 1;
	return *this;
};

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++(*this);
	return (temp);
};

Fixed Fixed::operator--() {
	this->fp -= 1;
	return *this;
};

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--(*this);
	return temp;
};

/*PUBLIC FUNCTIONS*/

int Fixed::getRawBits(void) const {
	std::cout << GREEN << "getRawBits member function called" << RESET << std::endl;
	return fp;
};
 
void Fixed::setRawBits(int const &raw) {
	fp = raw;
};

float Fixed::toFloat(void) const {
	return static_cast<float>(fp) / (1 << bits);
};

int Fixed::toInt(void) const {
	return fp >> bits;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
};

Fixed &Fixed::min(Fixed &x, Fixed &y) {
	return (x < y) ? x : y;
};

Fixed &Fixed::max(Fixed &x, Fixed &y) {
	return (x > y) ? x : y;
};

const Fixed &Fixed::min(const Fixed &x, const Fixed &y) {
	return (x < y) ? x : y;
};

const Fixed &Fixed::max(const Fixed &x, const Fixed &y) {
	return (x > y) ? x : y;
};

