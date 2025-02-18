/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:50:22 by cofische          #+#    #+#             */
/*   Updated: 2025/02/18 18:49:58 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <sstream>
#include <limits>
#include <ctime>
#include <deque>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include "../Colors.hpp"

/****************************************/
/********HELPER TEMPLATE FUNCTIONS*******/
/****************************************/

template <typename Container>
bool comp(int value1, const Container &cont) {
	return value1 < cont.back();
}

template <typename Vcontainer, typename VIterator>
VIterator upperBound(Vcontainer &cont, VIterator bound, int value) {
	VIterator it = cont.begin();

	for (; it <= bound; ++it) {
		if (comp(value, *it)) {
			return it;
		}
	}
	return ++bound;
}

template <typename V>
void printSequence(V &container) {
	typename V::iterator it = container.begin();
	for (; it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename Iterator>
void swapPairs(Iterator start, int nbrInPairs) {
	Iterator right = start;
	Iterator left = start;
	std::advance(left, -nbrInPairs);
	for (int i = 0; i < nbrInPairs; ++i) {
		std::iter_swap(right--, left--);
	}
}

template <typename Vec, typename Iterator>
Vec insertRange(Iterator start, Iterator end) {
	Vec pair;
	pair.insert(pair.end(), start, end);
	return pair;
}

/****************************************/
/********TEMPLATE CLASS TO SORT**********/
/****************************************/

template <typename T>
class PmergeMe {
	public:
		/******************************/
		/********CONSTRUCTORS**********/
		/******************************/
		
		PmergeMe(T &inputContainer) : container(inputContainer) {  
			FordJohnsonAlgo(1);
		}
		PmergeMe(const PmergeMe &other) : container(other.container) {}
		PmergeMe& operator=(const PmergeMe &other) {
			if (this != &other)
				container = other.container; 
			return *this; 
		}
		~PmergeMe() {};

		/******************************/
		/********TYPENAME DEF**********/
		/******************************/

		typedef typename T::iterator Iterator;
		typedef typename std::vector<T> Vec;
		typedef typename Vec::iterator it_vec;

		bool is_odd;
		Iterator start;
		Iterator last;
		Iterator end_pairs;

		/*************************/
		/********METHODS**********/
		/*************************/

		/****************************************/
		//	Calling recursively Ford_Johnson Algorithm to generate the pairs until having the set of {b1,a1} 
		//	If odd elements are detected, the odd_pairs are separated and store in a odd containers for later insertion
		//	Once the sequence has been split in pairs group, the sorting part start
		/****************************************/
		
		void FordJohnsonAlgo(int nbrInPairs) {
			int nbrOfPairs = container.size() / nbrInPairs;
			is_odd = nbrOfPairs % 2;
			if (nbrOfPairs <= 1) return;
			
			last = container.begin();
			std::advance(last, nbrInPairs * (nbrOfPairs) - 1);
			end_pairs = last;
			std::advance(end_pairs, -(nbrOfPairs % 2 == 1 ? nbrInPairs : 0));		
			Iterator it = end_pairs;
			for (int i = 0; i < nbrOfPairs / 2; ++i) {
				Iterator right = it;
				Iterator left = it;
				std::advance(left, -nbrInPairs);
				if (right != container.end() && left != container.end()) {
					if (*right < *left) {
						swapPairs(right, nbrInPairs);
					}
				}
				std::advance(it, -(2 * nbrInPairs));
			}
			T odd;
			if (is_odd) {
				Iterator it = end_pairs + 1;
				for (int i = 0; i < nbrInPairs; i++) {
					odd.push_back(*it++);
				}
			}
			FordJohnsonAlgo(nbrInPairs * 2);
			containerInitialisation(nbrInPairs, nbrOfPairs, odd);
		}
		
		/****************************************/
		//	For each recursive level, gennerate the main and pending container following Ford-Johnson algo
		//	We empty the main and pending containers from previous recursion before inserting pairs
		//	Main --> compose of B1 + A1 + all remaining As (A2,A3,A4 etc...)
		//	Pending -- > compose of B2 + all remining Bs (B3,B4,B5, etc...)
		//	Once the containers of pairs are ready, we sort this pairs level
		/****************************************/

		void containerInitialisation(int nbrInPairs, int nbrOfPairs, T &odd) {
			Vec main;
			Vec pend;
			if (!main.empty())
				main.clear();
			if (!pend.empty())
				pend.clear();
			start = container.begin();
			Iterator temp = start;
			std::advance(temp, nbrInPairs);
			main.insert(main.begin(), insertRange<T>(start, temp));
			start = temp;
			std::advance(temp, nbrInPairs);
			main.insert(main.end(), insertRange<T>(start, temp));
			for (int i = 2; i < nbrOfPairs - 1; i += 2) {
				Iterator pendStart = temp;
				Iterator pendEnd = pendStart;
				std::advance(pendEnd, nbrInPairs);
				pend.insert(pend.end(), insertRange<T>(pendStart, pendEnd));
				start = pendEnd;
				temp = start;
				std::advance(temp, nbrInPairs);
				main.insert(main.end(), insertRange<T>(start, temp));
			}
			jacobsthalSorting(main, pend);
			binarySorting(main, pend, nbrInPairs, nbrOfPairs, odd);
			storingSortedSequence(main, nbrInPairs);
		}
		
		/****************************************/
		//	Calculating the jacobsthal number to insert the pairs in order 
		//	If there is not enough pending elements, we directly move to binary insertion function
		//	example --> Jacobsthal = 3, the difference from previous is 3 - 1 = 2
		//	We insert 2 elements starting by the '3' or B3 than B2
		//	pending = { {b2}, {b3}} 
		//	main = { {b1}, {a1}, {a2}, {a3}}
		//	1st insertion is {b3}
		//	2nd insertion is {b2}
		//	For the insertion we use the binary insertion method with a custom upperBound function which return the index of the pair to insert in the main container
		/****************************************/
		
		void jacobsthalSorting(Vec &main, Vec &pend) {
			int prev_jacob = jacobsthal(1);
			int insertion = 0;
			int i = 2;
			while (1)
			{
				int curr_jacob = jacobsthal(i);
				int jacobsthal_diff = curr_jacob - prev_jacob;
				if (jacobsthal_diff > static_cast<int>(pend.size()))
					break;
				int insertion_nbr = jacobsthal_diff;
				it_vec pend_it = pend.begin();
				advance(pend_it, jacobsthal_diff - 1);
				it_vec bound_it = main.begin();
				advance(bound_it, curr_jacob + insertion);
				while (insertion_nbr) {
					it_vec idx = upperBound(main, bound_it, pend_it->back());
					main.insert(idx, *pend_it);
					insertion_nbr--;
					pend_it = pend.erase(pend_it);
					if (pend_it != pend.begin()) {
						std::advance(pend_it, -1);	
					}
					bound_it = main.begin() + (curr_jacob + insertion_nbr);
				}
				prev_jacob = curr_jacob;
				insertion += jacobsthal_diff;
				i++;
			}
		}
		
		/****************************************/
		//	We use the same method as for the jacobsthal insertion (binary insertion). 
		//	As we don't have enough element in pending, we insert them from right to left
		//	Once pending is empty, we insert the matching odd pair from Odd container if there is one
		/****************************************/

		void binarySorting(Vec &main, Vec &pend, int nbrInPairs, int nbrOfPairs, T &odd) {
			last = container.begin();
			std::advance(last, nbrInPairs * (nbrOfPairs) - 1);
			end_pairs = last;
			std::advance(end_pairs, -(nbrOfPairs % 2 == 1 ? nbrInPairs : 0));
			for (size_t i = 0; i < pend.size(); i++) {
				it_vec curr_pend = pend.begin();
				advance(curr_pend, i);
				it_vec curr_bound = main.begin();
				advance(curr_bound, main.size() - pend.size() + i);
				it_vec idx = upperBound(main, curr_bound, curr_pend->back());
				main.insert(idx, *curr_pend);
			}
			if (is_odd && !odd.empty()) {
				Iterator odd_pair_start = odd.begin();
				Iterator odd_pair_end = odd_pair_start;
				advance(odd_pair_end, nbrInPairs);
				Vec odd_pair;
				odd_pair.insert(odd_pair.begin(), insertRange<T>(odd_pair_start, odd_pair_end));
				it_vec curr = odd_pair.begin();
				it_vec bound = main.end() - 1;
				it_vec idx = upperBound(main, bound, curr->back());
				main.insert(idx, *curr);
			}
		}
		
		/****************************************/
		//	Once the pair sorting is done for this pair level, we copy the elements from main to a temp pairing container (vector of container)
		/****************************************/
		
		void storingSortedSequence(Vec &main, int nbrInPairs) {
			(void)nbrInPairs;
			Vec sortedContainer;
			for (it_vec it = main.begin(); it != main.end(); ++it) {
				T pair_start = *it;
				sortedContainer.insert(sortedContainer.end(), pair_start);
			}
			finalSequence(sortedContainer);
		}
		
		/****************************************/
		//	We clear the initial container and replace it with the sorting element of the temp pairing container
		//	To match the container format, we insert elements of the pairs one by one with a nesting for loop
		/****************************************/

		void finalSequence(Vec &sortedContainer) {
			container.clear();
			it_vec sortedContainer_it = sortedContainer.begin();
			for ( ; sortedContainer_it != sortedContainer.end(); ++sortedContainer_it) {
				Iterator it = sortedContainer_it->begin();
				for ( ; it != sortedContainer_it->end(); ++it) {
					container.push_back(*it);
				}
			}
		}
		
		static int jacobsthal(int jIndex) { return round((pow(2, jIndex + 1) + pow(-1, jIndex)) / 3); };

		const T &getContainer() const { return container; }
		
	private:
		T container;
};

/*************************************/
/********EXCEPTION FUNCTIONS**********/
/*************************************/

class PmergeError : public std::exception {
	private:
		const char *message;

	public:
		PmergeError(const char *msg) : message(msg) {};
		virtual const char *what() const throw() { return message; };
};

/*************************************/
/********OS OPERATOR OVERLOAD*********/
/*************************************/

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
