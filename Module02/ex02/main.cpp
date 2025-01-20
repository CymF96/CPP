/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:49:56 by cofische          #+#    #+#             */
/*   Updated: 2025/01/20 11:45:53 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c(Fixed(10) + Fixed(20));
	
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "New a =  " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "New a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "max(a,b)= " << Fixed::max( a, b ) << std::endl;

	std::cout << BOLD BLUE << "\narithmetic operators" << RESET << std::endl;
	std::cout << "\na = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "\na + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;

	std::cout << BOLD BLUE << "\ncomparison operators" << RESET << std::endl;
	std::cout << "\na = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "\na < b: " << (a < b) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	std::cout << BOLD BLUE << "\nMin function with FP" << RESET << std::endl;
	std::cout << "\na = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "\nMin between a and b: " << Fixed::min(a, b) << std::endl;
	std::cout << "Max between a and b: " << Fixed::max(a, b) << std::endl;

	std::cout << "\nMin function with Const FP" << std::endl;
	std::cout << "Min between b and c: " << Fixed::min(b, c) << std::endl;
	std::cout << "Max between b and c: " << Fixed::max(b, c) << std::endl;

	return 0;
}