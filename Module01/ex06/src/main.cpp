/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:01:50 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 18:14:32 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main(int ac, char **av) {
	Harl harl;
	std::cout << std::endl;
	
	if (ac < 2)
		std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
	else {
		std::string str(av[1]);
		harl.complain(str);
		std::cout << std::endl;
	}
	return (0);
}