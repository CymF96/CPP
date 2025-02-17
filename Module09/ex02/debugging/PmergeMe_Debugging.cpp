/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_Debugging.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:40:56 by cofische          #+#    #+#             */
/*   Updated: 2025/02/17 14:01:41 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe_Debugging.hpp"

/*******************************/
/********HELPER FUNCTIONS*******/
/*******************************/

void generateSequenceVector(std::vector<int> &sequence, char **input, size_t size) {
	int nb1;
	size_t i = 1;
	while (i < size)
	{
		nb1 = convertInt(input[i]);
		sequence.push_back(nb1);
		i++;
	}
};

void generateSequenceDeque(std::deque<int> &sequence, char **input, size_t size) {
	int nb1;
	size_t i = 1;
	while (i < size)
	{
		nb1 = convertInt(input[i]);
		sequence.push_back(nb1);
		i++;
	}
};

size_t getSize(char** arr) {
    size_t count = 0;
    while (arr[count]) {
        count++;
    }
    return count;
}

int convertInt(char *nbr) {
	std::istringstream iss(static_cast<std::string>(nbr));

	long nb;
	iss >> nb;

	if (iss.fail())
		throw PmergeError("unable to convert char* to int\n");
	else if (nb > std::numeric_limits<int>::max()) 
		throw PmergeError("number too large (INT_MAX limit reach)\n");
	else if (nb < 0)
		throw PmergeError("negative number not accepted\n");
	return static_cast<int>(nb);
};


// template <typename V>
// void printSequence(V &container) {
// 	typename V::iterator it = container.begin();
// 	for (; it != container.end(); ++it)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// }

