/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:29:02 by cofische          #+#    #+#             */
/*   Updated: 2025/02/05 14:30:44 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2 ) {
		std::cout <<  BOLD RED "Format Error " RESET "./btc nameFile" << std::endl;
		return (1);
	}

	std::string filename = av[1];
	try {
		BTC btc(filename);
	} catch (std::exception &e) {
		std::cout << BOLD RED "Error: " RESET << e.what();
	}
	return 0;
}