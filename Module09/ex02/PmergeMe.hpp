/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:50:22 by cofische          #+#    #+#             */
/*   Updated: 2025/02/12 18:39:56 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

template <typename T>
class PmergeMe {
	public:
		PmergeMe(T &container) { FJAS(container, 1); };
		PmergeMe(const PmergeMe &other) {(void)other; };
		PmergeMe& operator=(const PmergeMe &other) { (void)other; return *this; };
		~PmergeMe() {};

		typedef typename T::iterator Iterator;
		typedef typename std::vector<Iterator>::iterator it_itv;
		typedef typename std::vector<Iterator> itv;
		
		bool is_odd;
		int pairs;
		itv main;
		itv pend;


		void pairing (T &container, int level) {
			pairs = container.size() / level;
			if (pairs < 2)
				return;
			Iterator start = container.begin();
			Iterator last = next(container.begin(), level * (pairs));
			Iterator end = next(last, -(is_odd * level));
			int jump = 2 * level;
			for (Iterator it = start; it != end; std::advance(it, jump))
			{
				Iterator this_pair = next(it, level - 1);
				Iterator next_pair = next(it, level * 2 - 1);
				if (*this_pair > *next_pair)
				{
					_swap_pair(this_pair, level);
				}
			}
			FJAS(container, level * 2);
			containerInitialisation(container, level, pairs);
		}
		
		void containerInitialisation(T &container, int level, int pairs) {
			main.insert(main.end(), next(container.begin(), level - 1));
			main.insert(main.end(), next(container.begin(), level * 2 - 1));


			for (int i = 4; i <= pairs; i += 2)
			{
				pend.insert(pend.end(), next(container.begin(), level * (i - 1) - 1));
				main.insert(main.end(), next(container.begin(), level * i - 1));
			}
		}
		
		void jacobsthalSorting(T &container) {
			int prev_jacob = jacobsthal(1);
			int insertion = 0;
			for (int k = 2;; k++)
			{
				int curr_jacob = jacobsthal(k);
				int jacobsthal_diff = curr_jacob - prev_jacob;
				int offset = 0;
				if (jacobsthal_diff > static_cast<int>(pend.size()))
					break;
				int nbr_of_times = jacobsthal_diff;
				it_itv pend_it = next(pend.begin(), jacobsthal_diff - 1);
				it_itv bound_it = next(main.begin(), curr_jacob + insertion);
				while (nbr_of_times)
				{
					it_itv idx = std::upper_bound(main.begin(), bound_it, *pend_it, comp);
					it_itv inserted = main.insert(idx, *pend_it);
					nbr_of_times--;
					pend_it = pend.erase(pend_it);
					std::advance(pend_it, -1);
					offset += (inserted - main.begin()) == curr_jacob + insertion;
					bound_it = next(main.begin(), curr_jacob + insertion - offset);
				}
				prev_jacob = curr_jacob;
				insertion += jacobsthal_diff;
				offset = 0;
			}
		}
		
		void binarySorting(T &container, int level, int pairs) {
			Iterator last = next(container.begin(), level * (pairs));
			Iterator end = next(last, -(is_odd * level));
			for (size_t i = 0; i < pend.size(); i++) {
				it_itv curr_pend = next(pend.begin(), i);
				it_itv curr_bound = next(main.begin(), main.size() - pend.size() + i);
				it_itv idx = std::upper_bound(main.begin(), curr_bound, *curr_pend, comp);
				main.insert(idx, *curr_pend);
			}
			if (is_odd) {
				Iterator odd_pair = next(end, level - 1);
				it_itv idx = std::upper_bound(main.begin(), main.end(), odd_pair, comp);
				main.insert(idx, odd_pair);
			}
		}
		
		void storingSortedSequence(T &container, int level) {
			std::vector<int> copy;
			copy.reserve(container.size());
			for (it_itv it = main.begin(); it != main.end(); it++) {
				for (int i = 0; i < level; i++) {
					Iterator pair_start = *it;
					std::advance(pair_start, -level + i + 1);
					copy.insert(copy.end(), *pair_start);
				}
			}
		}

		void finalSequence(T &container) {
			Iterator container_it = container.begin();
			std::vector<int>::iterator copy_it = copy.begin();
			while (copy_it != copy.end())
			{
				*container_it = *copy_it;
				container_it++;
				copy_it++;
			}
		}
		
		void FJAS(T& container, int level) {
			pairing(container, level);
			jacobsthalSorting(container);
			binarySorting(container, level);
			storingSortedSequence(container, level);
			finalSequence(container);
		}

		bool comp(T lv, T rv) { return *lv < *rv; };
};

class PmergeError : public std::exception {
	private:
		const char *message;

	public:
		PmergeError(const char *msg) : message(msg) {};
		virtual const char *what() const throw() { return message; };
};

int convertInt(char *nbr);
int jacobsthal(int jIndex);
size_t getSize(char** arr);
