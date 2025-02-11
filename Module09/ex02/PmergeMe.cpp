/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:40:56 by cofische          #+#    #+#             */
/*   Updated: 2025/02/11 17:58:00 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

ddeq sequence;
ddeq pairs;
ddeq oddNumb;
vec vec1;
int flag = 0;

/*******************************/
/********CONSTRUCTORS***********/
/*******************************/

Pmerge::Pmerge() {};
Pmerge::~Pmerge() {};
Pmerge::Pmerge(const Pmerge &other) { (void)other; };
Pmerge &Pmerge::operator=(const Pmerge &other) { (void)other; return *this; };

/*******************************/
/********MEMBER FUNCTIONS*******/
/*******************************/

void Pmerge::sorted(char **input, size_t size) {
	generateSequence(input, size);
	pairing(sequence);
	std::cout << "size: " << pairs.size() << "\n";
	int pos = 0;
	for (size_t i = 0; i < pairs.size(); i++) {
		itv start = pairs[i].begin();
		itv end = pairs[i].end();
		std::cout << pos++ << ": ";
		for (; start != end; ++start) {
			std::cout << *start << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n";
	std::cout << "size: " << oddNumb.size() << "\n";
	pos = 0;
	for (size_t i = 0; i < oddNumb.size(); i++) {
		itv start = oddNumb[i].begin();
		itv end = oddNumb[i].end();
		std::cout << pos++ << ": ";
		for (; start != end; ++start) {
			std::cout << *start << " ";
		}
		std::cout << std::endl;
	}
};

void Pmerge::generateSequence(char **input, size_t size) {
	int nb1;
	size_t i = 1;
	while (i < size) {
		try {
			nb1 = convertInt(input[i]);
		} catch (std::exception &e) {
			std::cout << BOLD RED "Error: " RESET << e.what();
			flag = 1;
			return ;
		}
		vec1.push_back(nb1);
		sequence.push_back(vec1);
		vec1.clear();
		i++;
	}
};

void Pmerge::pairing(ddeq &inputSequence) {
	size_t size = inputSequence.size();
	if (size <= 2) {
		pairs = inputSequence;
		return;
	}
	ddeq tempPairs;
	size_t ind = 0;
	// int pos = 0;
	while (ind + 1 < size) {
		// std::cout << pos++ << ": " << sequence[ind] << "\n";
		int num1 = inputSequence[ind].back();
		int num2 = inputSequence[ind + 1].back();
		if (num2 < num1)
			inputSequence[ind].swap(inputSequence[ind + 1]);
		vec newPair = inputSequence[ind];
		newPair.insert(newPair.end(), inputSequence[ind + 1].begin(), inputSequence[ind + 1].end());
		tempPairs.push_back(newPair);
		newPair.clear();
		ind += 2;
	}
	if (ind < size)
		oddNumb.push_front(inputSequence.back());
	pairing(tempPairs);
}

/*******************************/
/********EXCEPTIONS*************/
/*******************************/

Pmerge::PmergeError::PmergeError(const char *msg) : message(msg) {};
const char *Pmerge::PmergeError::what() const throw() { return message; };

/*******************************/
/********HELPER FUNCTIONS*******/
/*******************************/
int convertInt(char *nbr) {
	std::istringstream iss(static_cast<std::string>(nbr));
	// std::cout << nbr << std::endl;
	long nb;
	iss >> nb;

	if (iss.fail())
		throw Pmerge::PmergeError("unable to convert char* to int\n");
	else if (nb > std::numeric_limits<int>::max()) 
		throw Pmerge::PmergeError("number too large (INT_MAX limit reach)\n");
	else if (nb < 0)
		throw Pmerge::PmergeError("negative number not accepted\n");
	return static_cast<int>(nb);
};

