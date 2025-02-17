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

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cout << BOLD RED "Format error: " RESET "./PmergeMe 1 2 3" << std::endl;
		return -1;
	}
	size_t size = getSize(av);
	std::vector<int> vec;
	try {
		generateSequenceVector(vec, av, size);
		std::cout << BOLD BLUE "\nBefore : " RESET;
		printSequence(vec);
	} catch (std::exception &e) {
		std::cerr << BOLD RED "Error: " RESET << e.what();
	}
	clock_t start = clock();
	PmergeMe<std::vector<int> > vecSort(vec);
	clock_t end = clock();
	std::cout << BOLD GREEN "After: " RESET << vecSort;
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "\t --> Time to process a range of " BOLD MAGENTA << size - 1 << RESET " elements with " BOLD " std::vector : " MAGENTA << duration << RESET " sec" << std::endl; 
	std::cout << std::endl;
	std::deque<int> deq;
	try {
		generateSequenceDeque(deq, av, ac);
		std::cout << BOLD BLUE "Before : " RESET;
		printSequence(deq);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	start = clock();
	PmergeMe<std::deque<int> > deqSort(deq);
	end = clock();
	std::cout << BOLD GREEN "After: " RESET << deqSort;
	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "\t --> Time to process a range of " BOLD MAGENTA << size - 1 << RESET " elements with " BOLD " std::deque : " MAGENTA << duration << RESET " sec" << std::endl; 
	std::cout << std::endl;
	return 0;
}
