/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:49:11 by cofische          #+#    #+#             */
/*   Updated: 2025/02/11 09:49:13 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe_Debugging.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cout << BOLD RED "Format error: " RESET "./PmergeMe 1 2 3" << std::endl;
		return -1;
	}
	size_t size = getSize(av);
	std::vector<int> vec;
	try {
		generateSequenceVector(vec, av, size);
	} catch (std::exception &e) {
		std::cerr << BOLD RED "Error: " RESET << e.what();
	}
	PmergeMe<std::vector<int> > vecSort(vec);
	std::cout << vecSort;
	std::cout << std::endl;
	std::deque<int> deq;
	try {
		generateSequenceDeque(deq, av, ac);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	// PmergeMe<std::deque<int> > deqSort(deq);
	// std::cout << deqSort;
	std::cout << std::endl;
	return 0;
}
