/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:01:35 by cofische          #+#    #+#             */
/*   Updated: 2025/01/20 12:04:51 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BSP.hpp"

float crossProduct(const Point &A, const Point &B, const Point &P) {
	return (B.getX().getRawBits() - A.getX().getRawBits()) * (P.getY().getRawBits() - A.getY().getRawBits()) -
		   (B.getY().getRawBits() - A.getY().getRawBits()) * (P.getX().getRawBits() - A.getX().getRawBits());
}

bool isPointInsideTriangle(const Point &A, const Point &B, const Point &C, const Point &P) {
	float crossAB = crossProduct(A, B, P);
	float crossBC = crossProduct(B, C, P);
	float crossCA = crossProduct(C, A, P);

	return (crossAB >= 0 && crossBC >= 0 && crossCA >= 0) || (crossAB <= 0 && crossBC <= 0 && crossCA <= 0);
}