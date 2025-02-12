/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:40:56 by cofische          #+#    #+#             */
/*   Updated: 2025/02/12 17:37:57 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


/*******************************/
/********MEMBER FUNCTIONS*******/
/*******************************/

/*******************************/
/********HELPER FUNCTIONS*******/
/*******************************/

int jacobsthal(int jIndex) {
	return round((pow(2, jIndex + 1) + pow(-1, jIndex)) / 3); 
}

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



