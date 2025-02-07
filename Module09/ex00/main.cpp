/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:29:02 by cofische          #+#    #+#             */
/*   Updated: 2025/02/07 09:38:55 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2 ) {
		std::cout <<  BOLD RED "Format Error " RESET "./btc nameFile" << std::endl;
		return (1);
	}

	std::string filename = av[1];
	BTC btc(filename);
	return 0;
}