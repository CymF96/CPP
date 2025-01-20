/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:15:31 by cofische          #+#    #+#             */
/*   Updated: 2025/01/20 16:54:40 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain() {
	std::cout << BOLD YELLOW << "Brain creation 🧠" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "Nothing";
}

Brain::~Brain() {
	std::cout << BOLD YELLOW << "Brain destroy" << RESET << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << BOLD YELLOW << "Copy Brain constructor" << RESET << std::endl;
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << BOLD YELLOW << "Copy Brain assignment" << RESET << std::endl;
	
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}
