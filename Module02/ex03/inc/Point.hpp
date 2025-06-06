/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:50:21 by cofische          #+#    #+#             */
/*   Updated: 2025/01/20 12:04:04 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Fixed.hpp"

class Point {
	public:
		Point(Fixed x, Fixed y);
		~Point();
		Point(const Point &other);
		Point &operator=(const Point &other);
		
		Fixed getX() const;
		Fixed getY() const;
		
	private:
		Fixed x, y;
};
