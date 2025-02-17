/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_Debugging.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:50:22 by cofische          #+#    #+#             */
/*   Updated: 2025/02/17 14:30:30 by cofische         ###   ########.fr       */
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
#include "../../Colors.hpp"

template <typename Container>
bool comp(int value1, const Container &cont) {
	return value1 < cont.back();
}

template <typename Vcontainer, typename VIterator>
VIterator upperBound(Vcontainer &cont, VIterator bound, int value) {
	VIterator it = cont.begin();

	for (; it <= bound; ++it) {
		std::cout << "INSIDE UPPERBOUND -- value: " << value << " containerValue: " << it->back() << "\n";
		if (comp(value, *it))
		{
			std::cout << "return value for comp: " << it->back() << "\n";
			return it;
		}
	}
	return cont.end();
}

template <typename V>
void printSequence(V &container) {
	typename V::iterator it = container.begin();
	for (; it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename V>
void printSequenceVector(std::vector<V> &container) {
	typename std::vector<V>::iterator it = container.begin();
	for (; it != container.end(); ++it) {
		for (typename V::iterator itv = it->begin(); itv != it->end(); ++itv) {
			std::cout << *itv << " ";
		}
		std::cout << std::endl;
	}
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

template <typename Vec, typename Iterator>
Vec insertRange(Iterator start, Iterator end) {
	Vec pair;
	pair.insert(pair.end(), start, end); // More efficient range insertion
	return pair;
}

template <typename T>
class PmergeMe {
	public:
		PmergeMe(T &inputContainer) : container(inputContainer), startInit(container.begin()) {  
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
		typedef typename std::vector<T> Vec;
		typedef typename Vec::iterator it_vec;
		typedef typename std::vector<Iterator>::iterator it_itv;
		typedef typename std::vector<Iterator> itv;

		bool is_odd;
		itv main;
		itv pend;
		it_vec start;
		Iterator last;
		Iterator end_pairs;

		void FJAS(int step) {
			std::cout << BOLD "\n" BG_BLUE "NEW PAIRING RECURSION" RESET "\n";
			std::cout << UNDERLINE "check Pairing\n" RESET;
			int pairs = container.size() / step;
			is_odd = pairs % 2;
			if (pairs <= 1) return;
			last = getIterator();
			std::advance(last, step * (pairs) - 1);
			end_pairs = last;
			std::advance(end_pairs, -(pairs % 2 == 1 ? step : 0));
			std::cout << "Pairs: " << pairs << "\n";
			std::cout << "Start: " << *startInit << "\n";
			std::cout << "Last: " << *last << "\n";
			std::cout << "End: " << *end_pairs << "\n";
			std::cout << "step: " << step << "\n";			
			Iterator it = end_pairs;
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
			T odd;
			if (is_odd) {
				std::cout << *end_pairs << "\n";
				Iterator it = end_pairs + 1;
				for (int i = 0; i < step; i++) {
					odd.push_back(*it++);
				}
				std::cout << BOLD MAGENTA "Odd: " RESET;
				printSequence(odd);
			}

			std::cout << std::endl;
			FJAS(step * 2);
			std::cout << BOLD "\n" BG_YELLOW "NEW RECURSION" RESET "\n";
			containerInitialisation(step, pairs, odd);
		}
		
		void containerInitialisation(int step, int pairs, T &odd) {
			Vec main1;
			Vec pend1;
			if (!main1.empty())
				main.clear();
			if (!pend1.empty())
				pend1.clear();
			std::cout << UNDERLINE "check Init container\n" RESET;
			Iterator start = container.begin();
			Iterator temp = start;
			std::cout << "Step: " << step << ", Pairs: " << pairs << "\n";
			std::advance(temp, step);
			std::cout << "\nB1: " << *start << " to " << *(temp-1) << "\n";
			main1.insert(main1.begin(), insertRange<T>(start, temp));
			start = temp;
			std::advance(temp, step);
			std::cout << "A1: " << *start << " to " << *(temp-1) << "\n";
			main1.insert(main1.end(), insertRange<T>(start, temp));
			std::cout << BOLD MAGENTA "Container main: " RESET;
			printSequenceVector<T>(main1);
			for (int i = 2; i < pairs - 1; i += 2) {
				Iterator pendStart = temp;
				Iterator pendEnd = pendStart;
				std::advance(pendEnd, step);
				std::cout << "\nB2: " << *pendStart << " to " << *(pendEnd-1) << "\n";
				pend1.insert(pend1.end(), insertRange<T>(pendStart, pendEnd));
				std::cout << BOLD MAGENTA "Container pending: " RESET;
				printSequenceVector<T>(pend1);
				start = pendEnd;
				temp = start;
				std::advance(temp, step);
				std::cout << "\nA2: " << *start << " to " << *(temp-1) << "\n";
				main1.insert(main1.end(), insertRange<T>(start, temp));
				std::cout << BOLD MAGENTA "New container main: " RESET;
				printSequenceVector<T>(main1);
			}
			jacobsthalSorting(main1, pend1);
			binarySorting(main1, pend1, step, pairs, odd);
			storingSortedSequence(main1, step);
		}
		
		void jacobsthalSorting(Vec &main, Vec &pend) {
			std::cout << UNDERLINE "\ncheck Jacobsthal sorting\n" RESET;
			int prev_jacob = jacobsthal(1);
			int insertion = 0;
			int i = 2;
			while (1)
			{
				std::cout << BG_BRIGHT_YELLOW BOLD BLACK"\nIN OUTER LOOP\n" RESET;
				int curr_jacob = jacobsthal(i);
				int jacobsthal_diff = curr_jacob - prev_jacob;
				std::cout << BOLD CYAN "curr_jacob: " RESET << curr_jacob << BOLD CYAN ", jacob_diff: " RESET << jacobsthal_diff << BOLD CYAN ", pendSize: " RESET << pend.size() << "\n";
				if (jacobsthal_diff > static_cast<int>(pend.size()))
					break;
				int insertion_nbr = jacobsthal_diff;
				std::cout << BOLD CYAN "Insertion_nbr: " RESET << insertion_nbr << "\n";
				std::cout << BOLD MAGENTA "Main: " RESET "\n";
				printSequenceVector(main);
				std::cout << BOLD MAGENTA "Pend: " RESET "\n";
				printSequenceVector(pend);
				it_vec pend_it = pend.begin();
				advance(pend_it, jacobsthal_diff - 1);
				it_vec bound_it = main.begin();
				advance(bound_it, curr_jacob + insertion);
				std::cout << "pend_it->back(): " << (pend_it->back()) << "\n";
				std::cout << "bound_it->back(): " << (bound_it->back()) << "\n";
				std::cout << BG_BRIGHT_GREEN BOLD BLACK"\nIN LOOP\n" RESET;
				while (insertion_nbr) {
					// std::cout << "pend_it->back() in loop: " << (pend_it->back()) << "\n";
					// std::cout << "bound_it->back() in loop: " << (bound_it->back()) << "\n";
					it_vec idx = upperBound(main, bound_it, pend_it->back());
					main.insert(idx, *pend_it); //it_vec inserted = 
					std::cout << BOLD MAGENTA "Main in loop: " RESET "\n";
					printSequenceVector(main);
					insertion_nbr--;
					pend_it = pend.erase(pend_it);
					if (pend_it != pend.begin()){
						std::advance(pend_it, -1);	
					}
					std::cout << "pend_it->back() in loop: " << ((pend_it)->back()) << " -- pend.begin()->back() in loop: " << ((pend.begin())->back()) <<"\n";
					bound_it = main.begin() + (curr_jacob + insertion_nbr);
					std::cout << "bound_it->back() in loop: " << (bound_it->back()) << "\n";
				}
				prev_jacob = curr_jacob;
				insertion += jacobsthal_diff;
				i++;
			}
		}
		
		void binarySorting(Vec &main, Vec &pend, int step, int pairs, T &odd) {
			std::cout << UNDERLINE "\ncheck Binary sorting\n" RESET;
			last = container.begin();
			std::advance(last, step * (pairs) - 1);
			end_pairs = last;
			std::advance(end_pairs, -(pairs % 2 == 1 ? step : 0));
			std::cout << "Pairs: " << pairs << ", start: " << *startInit << ", last: " << *last << ", End: " << *end_pairs << ", step: " << step << "\n";	
			std::cout << "pend.size: " << pend.size() << "\n";
			for (size_t i = 0; i < pend.size(); i++) {
				it_vec curr_pend = pend.begin();
				advance(curr_pend, i);
				std::cout << "curr_pend->pack(): " << (curr_pend->back()) << "\n";
				it_vec curr_bound = main.begin();
				advance(curr_bound, main.size() - pend.size() + i);
				std::cout << "curr_bound->back(): " << (curr_bound->back()) << "\n";
				it_vec idx = upperBound(main, curr_bound, curr_pend->back());
				main.insert(idx, *curr_pend);
				std::cout << BOLD MAGENTA "New container main: " RESET;
				printSequenceVector<T>(main);
			}
			if (is_odd && !odd.empty()) {
				// (void)odd;
				Iterator odd_pair_start = odd.begin();
				Iterator odd_pair_end = odd_pair_start;
				advance(odd_pair_end, step);
				Vec odd_pair;
				odd_pair.insert(odd_pair.begin(), insertRange<T>(odd_pair_start, odd_pair_end));
				std::cout << "odd_pair: " << *(odd_pair_start) << ", odd_pair_end: " << *(odd_pair_end - 1) << " odd_pair size: " << odd_pair.size() << "\n";
				std::cout << BOLD MAGENTA "Odd_pair: " RESET;
				printSequenceVector<T>(odd_pair);
				it_vec curr = odd_pair.begin();
				it_vec bound = main.end() - 1;
				std::cout << "curr_pair: " << (curr->back()) << "\n";
				it_vec idx = upperBound(main, bound, curr->back());
				main.insert(idx, *curr);
			}
		}
		
		void storingSortedSequence(Vec &main, int step) {
			std::cout << "\ncheck sorting sequence\n";
			(void)step;
			Vec sortedContainer;
			for (it_vec it = main.begin(); it != main.end(); ++it) {
				T pair_start = *it;
				sortedContainer.insert(sortedContainer.end(), pair_start);
			}
			std::cout << BOLD MAGENTA "New sorted container pairs: " RESET;
			printSequenceVector<T>(sortedContainer);
			finalSequence(sortedContainer);
		}

		void finalSequence(Vec &sortedContainer) {
			std::cout << "\ncheck finalSequence\n\n";
			int index = container.size();
			std::cout << "index: " << index << "\n";
			container.clear();
			it_vec sortedContainer_it = sortedContainer.begin();
			for ( ; sortedContainer_it != sortedContainer.end(); ++sortedContainer_it) {
				Iterator it = sortedContainer_it->begin();
				for ( ; it != sortedContainer_it->end(); ++it) {
					container.push_back(*it);
				}
			}
			std::cout << BOLD RED "New sorted container: " RESET;
			printSequence(container);
		}
		
		static int jacobsthal(int jIndex) { return round((pow(2, jIndex + 1) + pow(-1, jIndex)) / 3); };

		const T &getContainer() const { return container; }
		const Iterator getIterator() { return startInit; }
		
	private:
		T container;
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
