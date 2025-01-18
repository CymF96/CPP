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

	Fixed Ax, Ay, Bx, By, Cx, Cy, Px, Py;

	std::cout 	<< BOLD << "*************************\nWelcome to BSP program!\n*************************\n\n" << RESET 
				<< "Please enter the triangle coordinates and the point to check:" << std::endl;
	std::cout << "A -x: ";
	std::cin >> Ax;
	std::cout << "A -y: ";
	std::cin >> Ay;
	std::cout << "B -x: ";
	std::cin >> Bx;
	std::cout << "B -y: ";
	std::cin >> By;
	std::cout << "C -x: ";
	std::cin >> Cx;
	std::cout << "C -y: ";
	std::cin >> Cy;
	std::cout << "P -x: ";
	std::cin >> Px;
	std::cout << "P -y: ";
	std::cin >> Py;
	std::cout << std::endl;

	Point A(Ax, Ay);
	Point B(Bx, By);
	Point C(Cx, Cy);
	Point P(Px, Py);

	if (isPointInsideTriangle(A, B, C, P)) {
		std::cout << "\nBSP result: "; 
		std::cout << BOLD BLUE <<"The point is inside the triangle." << RESET << std::endl;
	} else {
		std::cout << "\nBSP result: " << std::endl; 
		std::cout << BOLD RED << "The point is outside the triangle." << RESET << std::endl;
	}
	std::cout << std::endl;

	return 0;
}