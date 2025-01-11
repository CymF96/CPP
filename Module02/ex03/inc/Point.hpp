/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:50:21 by cofische          #+#    #+#             */
/*   Updated: 2025/01/11 13:19:03 by cofische         ###   ########.fr       */
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

bool isPointInsideTriangle(const Point &A, const Point &B, const Point &C, const Point &P);
float crossProduct(const Point &A, const Point &B, const Point &P);