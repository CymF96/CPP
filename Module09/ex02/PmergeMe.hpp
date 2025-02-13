/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:50:22 by cofische          #+#    #+#             */
/*   Updated: 2025/02/13 17:13:20 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <sstream>
#include <limits>
#include <deque>
#include <math.h>
#include <algorithm>
#include "../Colors.hpp"

template <typename Iterator>
bool comp(const Iterator& it1, const Iterator& it2) {
        return *it1 < *it2;
};

template <typename V>
void printSequence(V &container) {
	typename V::iterator it = container.begin();
	std::cout << BOLD BLUE "Sequence: " RESET;
	for (; it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename V>
void printSequenceIterator(V &container) {
	typename V::iterator it = container.begin();
	std::cout << BOLD YELLOW "Sequence of pointers: " RESET;
	for (; it != container.end(); ++it)
		std::cout << **it << " ";
	std::cout << std::endl;
}

template <typename Iterator>
void swapPairs(Iterator start, int step) {
    Iterator right = start;  // Points to the end of the right pair
    Iterator left = start;
    std::advance(left, -step); // Points to the end of the left pair

    std::cout << BOLD GREEN "In swapping," RESET " right: " << *right << ", left: " << *left << "\n";

    // Swap the sequences element-by-element
    for (int i = 0; i < step; ++i) {
        std::iter_swap(right--, left--);
    }
}


template <typename T>
class PmergeMe {
	public:
		PmergeMe(T &inputContainer) : container(inputContainer), startInit(container.begin()) {  
			sortedContainer.resize(container.size());
			FJAS(1);
		}
		PmergeMe(const PmergeMe &other) : container(other.container) {}
		PmergeMe& operator=(const PmergeMe &other) {
			if (this != &other)
				container = other.container; 
			return *this; 
		}
		~PmergeMe() {};

		typedef typename T::iterator Iterator;
		typedef typename std::vector<Iterator>::iterator it_itv;
		typedef typename std::vector<Iterator> itv;

		bool is_odd;
		itv main;
		itv pend;
		Iterator last;
		Iterator end;

		void FJAS(int step) {
			is_odd = 0;
			pairs = 0;
			pairing(step);
			containerInitialisation(step);
			jacobsthalSorting();
			binarySorting(step);
			storingSortedSequence(step);
			finalSequence();
			std::cout << BOLD "\n" BG_YELLOW "NEW RECURSION" RESET "\n";
		}

		void pairing(int step) {
			std::cout << UNDERLINE "check Pairing\n" RESET;
			int pairs = container.size() / step;
			if (pairs <= 2) return;
			last = getIterator();
			std::advance(last, step * (pairs) - 1);
			end = last;
			std::advance(end, -(pairs % 2 == 1 ? step : 0));
			std::cout << "Pairs: " << pairs << "\n";
			std::cout << "Start: " << *startInit << "\n";
			std::cout << "Last: " << *last << "\n";
			std::cout << "End: " << *end << "\n";
			std::cout << "step: " << step << "\n";			
			Iterator it = end;
			for (int i = 0; i < pairs / 2; ++i) {
				Iterator right = it;
				Iterator left = it;
				std::advance(left, -step);
				std::cout << "Comparing: " << *right << " and " << *left << "\n";
				if (right != container.end() && left != container.end()) {
					if (*right < *left) {
						swapPairs(right, step);
						std::cout << "Swapped: " << *right << " and " << *left << "\n";
					}
				}
				printSequence(container);
				std::advance(it, -(2 * step));
			}
			std::cout << std::endl;
			FJAS(step * 2);
		}
		
		void containerInitialisation(int step) {
			std::cout << UNDERLINE "check Init container\n" RESET;
			Iterator start = container.begin();
			Iterator temp = start;
			std::advance(temp, pairs * 2 - 1);
			std::cout << BOLD MAGENTA "\nContainer: " RESET;
			std::cout << *temp;
			main.insert(main.end(), temp);
			std::advance(temp, (pairs * 2));
			main.insert(main.end(), temp);
			std::cout << " " << *temp << " step: " << step / 2 << " pairs: " << pairs << std::endl;; 
			printSequenceIterator(main);
			for (int i = 4; i <= pairs; i += 2) {
				Iterator pendTemp = start;
				std::advance(pendTemp, step * (i - 1) - 1);
				pend.insert(pend.end(), pendTemp);
				printSequenceIterator(pend);
				Iterator mainTemp = start;
				std::advance(mainTemp, step * i - 1);
				main.insert(main.end(), mainTemp);
			}
		}
		
		void jacobsthalSorting() {
			std::cout << UNDERLINE "\ncheck Jacobsthal sorting\n" RESET;
			int prev_jacob = jacobsthal(1);
			std::cout << BOLD CYAN "Jacobsthal: " << prev_jacob << "\n";
			int insertion = 0;
			int i = 2;
			while (1)
			{
				int curr_jacob = jacobsthal(i);
				int jacobsthal_diff = curr_jacob - prev_jacob;
				std::cout << BOLD CYAN "curr_jacob: " RESET << curr_jacob << BOLD CYAN ", jacob_diff: " RESET << jacobsthal_diff << "\n";
				int offset = 0;
				if (jacobsthal_diff > static_cast<int>(pend.size()))
					break;
				int nbr_of_times = jacobsthal_diff;
				std::cout << "enough jacobsthal?\n";
				it_itv pend_it = pend.begin();
				advance(pend_it, jacobsthal_diff - 1);
				it_itv bound_it = main.begin();
				advance(bound_it, curr_jacob + insertion);
				while (nbr_of_times)
				{
					it_itv idx = std::upper_bound(main.begin(), bound_it, *pend_it, comp<Iterator>);
					it_itv inserted = main.insert(idx, *pend_it);
					nbr_of_times--;
					pend_it = pend.erase(pend_it);
					std::advance(pend_it, -1);
					offset += (inserted - main.begin()) == curr_jacob + insertion;
					advance(bound_it, curr_jacob + insertion - offset);
				}
				prev_jacob = curr_jacob;
				insertion += jacobsthal_diff;
				offset = 0;
				i++;
			}
		}
		
		void binarySorting(int step) {
			std::cout << UNDERLINE "\ncheck Binary sorting\n" RESET;
			last = container.begin();
			std::advance(last, step * (pairs) - 1);
			end = last;
			std::advance(end, -(pairs % 2 == 1 ? step : 0));
			std::cout << "Pairs: " << pairs << "\n";
			std::cout << "Start: " << *startInit << "\n";
			std::cout << "Last: " << *last << "\n";
			std::cout << "End: " << *end << "\n";
			std::cout << "step: " << step << "\n";	
			for (size_t i = 0; i < pend.size(); i++) {
				it_itv curr_pend = pend.begin();
				advance(curr_pend, i);
				it_itv curr_bound = main.begin();
				advance(curr_bound, main.size() - pend.size() + i);
				it_itv idx = std::upper_bound(main.begin(), curr_bound, *curr_pend, comp<Iterator>);
				main.insert(idx, *curr_pend);
			}
			if (is_odd) {
				Iterator odd_pair = end;
				advance(odd_pair, step - 1);
				it_itv idx = std::upper_bound(main.begin(), main.end(), odd_pair, comp<Iterator>);
				main.insert(idx, odd_pair);
			}
		}
		
		void storingSortedSequence(int step) {
			std::cout << "\ncheck sorting sequence\n";
			for (it_itv it = main.begin(); it != main.end(); ++it) {
				Iterator pair_start = *it;
				for (int i = 0; i < step; ++i) {
					Iterator curr = pair_start;
					std::advance(curr, i);
					sortedContainer.push_back(*curr);
				}
			}
		}

		void finalSequence() {
			std::cout << "\ncheck finalSequence\n";
			Iterator container_it = container.begin();
			Iterator sortedContainer_it = sortedContainer.begin();
			while (sortedContainer_it != sortedContainer.end()) {
				*container_it = *sortedContainer_it;
				container_it++;
				sortedContainer_it++;
			}
		}
		
		static int jacobsthal(int jIndex) { return round((pow(2, jIndex + 1) + pow(-1, jIndex)) / 3); };

		const T &getContainer() const { return sortedContainer; }
		const Iterator getIterator() { return startInit; }
	private:
		T container;
		T sortedContainer;
		Iterator startInit;
};

class PmergeError : public std::exception {
	private:
		const char *message;

	public:
		PmergeError(const char *msg) : message(msg) {};
		virtual const char *what() const throw() { return message; };
};

template <typename U>
std::ostream &operator<<(std::ostream &os, const PmergeMe <U> &obj) {
	typename U::const_iterator it = obj.getContainer().begin();
	for (; it != obj.getContainer().end(); ++it)
		os << *it << " ";
	os << "\n";
	return os;
};

int convertInt(char *nbr);
size_t getSize(char** arr);
void generateSequenceDeque(std::deque<int> &sequence, char **input, size_t size);
void generateSequenceVector(std::vector<int> &sequence, char **input, size_t size);
