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

void generateSequenceVector(std::vector<int> &sequence, char **input, size_t size)
{
	int nb1;
	size_t i = 1;
	while (i < size)
	{
		nb1 = convertInt(input[i]);
		sequence.push_back(nb1);
		i++;
	}
};

void generateSequenceDeque(std::deque<int> &sequence, char **input, size_t size)
{
	int nb1;
	size_t i = 1;
	while (i < size)
	{
		nb1 = convertInt(input[i]);
		sequence.push_back(nb1);
		i++;
	}
};

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
	PmergeMe(vec);

	std::deque<int> deq;
	try {
		generateSequenceDeque(deq, av, size);
	} catch (std::exception &e) {
		std::cerr << BOLD RED "Error: " RESET << e.what();
	}
	PmergeMe(deq);
    return 0;
}