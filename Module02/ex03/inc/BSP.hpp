/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:04:12 by cofische          #+#    #+#             */
/*   Updated: 2025/01/20 12:04:43 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool isPointInsideTriangle(const Point &A, const Point &B, const Point &C, const Point &P);
float crossProduct(const Point &A, const Point &B, const Point &P);
