/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:12:13 by cofische          #+#    #+#             */
/*   Updated: 2025/02/07 17:29:21 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2 || static_cast<std::string>(av[1]).empty()) {
		std::cerr << BOLD RED "Format error: " RESET "./RPN \"notation\"" << std::endl;
		return -1;
	}
	std::string notation = av[1];
	removeSpace(notation);
	try {
		checkInput(notation);
	} catch (std::exception &e) {
		std::cerr << BOLD RED "Error: " RESET << e.what() << " --> " BOLD MAGENTA << av[1] << RESET << std::endl;
		return -2;
	} try {
		RPN::operation(notation);
	} catch (std::exception &e) {
		std::cerr << BOLD RED "Error: " RESET << e.what() << " --> " BOLD MAGENTA << av[1] << RESET << std::endl;
		return - 2;
	}
	return 0;
}