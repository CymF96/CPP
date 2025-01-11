/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:53:54 by cofische          #+#    #+#             */
/*   Updated: 2025/01/11 13:18:57 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"
#include "../inc/Fixed.hpp"

Point::Point(Fixed inputX, Fixed inputY) : x(inputX), y(inputY) {
	std::cout << "Default Point constructor called\n" << std::endl;
};

Point::~Point() {
	std::cout << "Point deconstructor called\n" << std::endl;
};

Point::Point(const Point &other) : x(other.x), y(other.y) {
	std::cout << "Point copy constructor called\n" << std::endl;
};

Point &Point::operator=(const Point &other) {
	if (this != &other) {
		x = other.x;
		y = other.y;
	}
	return (*this);
};

Fixed Point::getX() const {
	return x;
};

Fixed Point::getY() const {
	return y;
};
