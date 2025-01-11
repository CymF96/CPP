/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:49:56 by cofische          #+#    #+#             */
/*   Updated: 2025/01/11 13:13:31 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

int main() {

	Point A(Fixed(1.0f), Fixed(1.0f));
	Point B(Fixed(3.0f), Fixed(4.0f));
	Point C(Fixed(5.0f), Fixed(2.0f));
	Point P(Fixed(2.0f), Fixed(2.0f));


	if (isPointInsideTriangle(A, B, C, P)) {
		std::cout << "The point is inside the triangle." << std::endl;
	} else {
		std::cout << "The point is outside the triangle." << std::endl;
	}

	return 0;
}