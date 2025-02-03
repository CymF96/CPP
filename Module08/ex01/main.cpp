/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:25:08 by cofische          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:15 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	unsigned int max = 100001;
	srand(time(0));
	
	Span sp1 = Span(max);
	Span sp2 = Span(max / 2);
	try {
		for (size_t i = 0; i < (max / 2); i++) {
			int random = rand() % 1000;
			sp1.addNumber(random);
		} 
	} catch (std::exception &e) {
		std::cout << BOLD RED "Error: " RESET << e.what();
	} try {
		for (size_t i = 0; i < (max / 2); i++) {
			int random = rand() % 1000;
			sp2.addNumber(random);
		}
	} catch (std::exception &e) {
		std::cout << BOLD RED "Error: " RESET << e.what();
	}
	int initSizeSp1 = sp1.intVector.size();
	int initSizeSp2 = sp2.intVector.size();
	
	try {
		sp1.addManyNumber(sp2);
	} catch (std::exception &e) {
		std::cout << BOLD RED "Error: " RESET << e.what();
	}
	// std::cout << sp1;
	std::cout << BOLD GREEN "Initial container size (Sp1): " RESET << initSizeSp1 << std::endl;
	std::cout << BOLD GREEN "Initial container size (Sp2): " RESET << initSizeSp2 << std::endl;

	return 0;
}