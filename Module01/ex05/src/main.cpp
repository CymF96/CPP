/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:01:50 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 18:08:39 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main() {
	Harl harl;
	std::cout << std::endl;
	
	std::string inputLevel;
	std::cout << "Please enter Harl's level of complaining\nLevels: " << BOLD YELLOW << "DEBUG, INFO, WARNING, ERROR\n" << RESET << std::endl;
	std::cin >> inputLevel;
	
	harl.complain(inputLevel);
	std::cout << std::endl;
	return (0);
}