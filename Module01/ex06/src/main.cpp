/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:01:50 by cofische          #+#    #+#             */
/*   Updated: 2025/01/08 12:43:08 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
	
	if (ac < 2)
		return (1);
	std::string str(av[1]);
	Harl harl;
	if (str.compare("I am not sure how tired I am today...") == 0)
		std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
	else {
		harl.complain(str);
		std::cout << std::endl;
	}
	return (0);
}