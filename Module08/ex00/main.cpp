/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:42:55 by cofische          #+#    #+#             */
/*   Updated: 2025/02/03 12:23:31 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

int main() {
	std::vector<int> vec;
	int pos = 0;
	int x = 2;
	
	for (int i = 0; i < 100; i++)
		vec.push_back(x += 2);

	std::vector<int>::iterator it;
	
	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << BOLD BLUE << pos++ << ": " RESET << *it << " // ";
	std::cout << std::endl;
	
	int w = 62;
	int y = 8;
	int z = 57;
	try {
		easyfind(vec, y);
		easyfind(vec, w);
		easyfind(vec, z);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	return 0;
}