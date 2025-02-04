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
	/*****************************/
	/**TRY TO ADD SINGLE NUMBER***/
	/*****************************/
	{
		std::cout << BOLD "\n***SINGLE ADDNUMBER ARRAY***\n";
		Span sp = Span(5);
		Span spTest = Span(0);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		try {
			std::cout << spTest.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << BOLD RED "ERROR: " RESET << e.what();
		} try  {
			std::cout << spTest.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << BOLD RED "ERROR: " RESET << e.what();
		}
	}
	/********************************************/
	/**TRY TO ADD SPAN WITH SAME VALUE ARRAY*****/
	/********************************************/
	{
		std::cout << BOLD "\n***SAME VALUE ARRAY***\n";
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(6);
		sp.addNumber(6);
		sp.addNumber(6);
		sp.addNumber(6);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	/*****************************/
	/**TRY TO ADD MANY NUMBER*****/
	/*****************************/
	std::cout << BOLD "\n***LARGE ADDNUMBER ARRAY***\n";
	unsigned int max = 100001;
	Span sp1 = Span(max);
	Span sp2 = Span(max/2 + 1);
	try {
		int begin = 0;
		int end =  (max / 2);
		sp1.addManyNumber(begin, end);
	} catch (std::exception &e) {
		std::cout << BOLD RED "Error: " RESET << e.what();
	} try {
		int begin = 0;
		int end = (max / 2);
		sp2.addManyNumber(begin, end);
	} catch (std::exception &e) {
		std::cout << BOLD RED "Error: " RESET << e.what();
	}

	// srand(time(0));
	
	// Span sp1 = Span(10);
	// Span sp2 = Span(5);
	// try {
	// 	int begin = 0;
	// 	int end = 9;
	// 	sp1.addManyNumber(begin, end);
	// } catch (std::exception &e) {
	// 	std::cout << BOLD RED "Error: " RESET << e.what();
	// } try {
	// 	int begin = 0;
	// 	int end = 4;
	// 	sp2.addManyNumber(begin, end);
	// } catch (std::exception &e) {
	// 	std::cout << BOLD RED "Error: " RESET << e.what();
	// }
	int initSizeSp1 = sp1.intVector.size();
	int initSizeSp2 = sp2.intVector.size();
	// std::cout << BOLD << "Initial Sp1:\n" << sp1;
	// std::cout << BOLD << "Initial Sp1:\n" << sp2;

	/*****************************/
	/**TRY TO APPEND ARRAY********/
	/*****************************/
	try {
		sp1.appendArray(sp2);
	} catch (std::exception &e) {
		std::cout << BOLD RED "Error: " RESET << e.what();
	}
	int SizeSp1 = sp1.intVector.size();
	// std::cout << sp1;
	std::cout << BOLD GREEN "Initial container size (Sp1): " RESET << initSizeSp1 << std::endl;
	std::cout << BOLD MAGENTA "New container size (Sp1) after append: " RESET << SizeSp1 << std::endl;
	std::cout << BOLD GREEN "Initial container size (Sp2): " RESET << initSizeSp2 << std::endl;

	return 0;
}