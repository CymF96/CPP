/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:01:50 by cofische          #+#    #+#             */
/*   Updated: 2025/01/08 12:10:29 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
	Harl harl;
	std::string inputLevel;
	std::cout << "Please enter Harl's level of complaining\nLevels: " << BOLD YELLOW << "DEBUG, INFO, WARNING, ERROR\n" << RESET << std::endl;
	std::cin >> inputLevel;
	harl.complain(inputLevel);
	std::cout << std::endl;
	return (0);
}