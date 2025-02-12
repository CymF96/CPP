/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:34:52 by cofische          #+#    #+#             */
/*   Updated: 2025/02/12 17:46:26 by cofische         ###   ########.fr       */
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

template <typename Container>
class Pmerge {
	public:
		Pmerge(Container &sequence) {
			pairing(sequence);
			std::cout << BOLD BLUE "PAIRING\n" RESET;
			printContainer(pairs);
			sorting(pairs, 2);
			std::cout << BOLD BLUE "\nSORTING\n" RESET;
			printContainer(pairs);
		}
		// ~Pmerge() {};
		// Pmerge(const Pmerge &other) { (void)other; };
		// Pmerge &operator=(const Pmerge &other) { (void)other; return *this; };
		
		Container pairs;
		Container oddNumb;

		typedef typename Container::value_type InnerContainer;
		typedef typename Container::iterator Iterator;
			
		void pairing(Container &inputSequence) {
			size_t size = inputSequence.size();
			if (size <= 2) {
				pairs = inputSequence;
				return;
			}

			Container tempPairs;
			size_t ind = 0;
			while (ind + 1 < size) {
				int num1 = inputSequence[ind].back();
				int num2 = inputSequence[ind + 1].back();
				if (num2 < num1)
					std::swap(inputSequence[ind], inputSequence[ind + 1]);
				
				InnerContainer newPair = inputSequence[ind];
				newPair.insert(newPair.end(), inputSequence[ind + 1].begin(), inputSequence[ind + 1].end());
				tempPairs.push_back(newPair);
				ind += 2;
			}
			if (ind < size)
				oddNumb.push_front(inputSequence.back());
			
			pairing(tempPairs);
		}

		void sorting(Container &main, int level)
		{
			if (main.size() <= 1)
				return;

			level += 2;
			Container pend, tempMain;

			// Step 1: Split `main` into smaller subgroups
			for (Iterator beg = main.begin(); beg != main.end(); ++beg)
			{
				InnerContainer vec1 = *beg;
				typename InnerContainer::iterator itvec = vec1.begin();
				InnerContainer temp;
				for (; itvec != vec1.end(); ++itvec)
				{
					for (int i = 0; i < level && itvec != vec1.end(); i++)
						temp.push_back(*itvec++);
					tempMain.push_back(temp);
					temp.clear();
					--itvec;
				}
			}
			main = tempMain;
			tempMain.clear();

			// Step 2: Populate `pend` with elements to be inserted later
			for (Iterator beg = main.begin() + 2; beg != main.end(); ++beg)
			{
				pend.push_front(*beg);
				main.erase(beg);
			}

			// Step 3: Insert `pend` elements into `main` using Jacobsthal sequence
			int prev_jacobsthal = jacobsthal(1);
			int inserted_numbers = 0;
			for (int Jindex = 2;; Jindex++)
			{
				int curr_jacobsthal = jacobsthal(Jindex);
				int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
				int offset = 0;

				if (jacobsthal_diff > static_cast<int>(pend.size()))
					break;

				Iterator pend_it = pend.begin();
				std::advance(pend_it, jacobsthal_diff - 1);
				Iterator bound_it = main.begin();
				std::advance(bound_it, curr_jacobsthal + inserted_numbers);

				int nbr_of_times = jacobsthal_diff;
				while (nbr_of_times--)
				{
					Iterator idx = std::upper_bound(main.begin(), bound_it, *pend_it);
					Iterator inserted = main.insert(idx, *pend_it);
					pend_it = pend.erase(pend_it);
					std::advance(pend_it, -1);

					offset += (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
					bound_it = main.begin();
					std::advance(bound_it, curr_jacobsthal + inserted_numbers - offset);
				}
				prev_jacobsthal = curr_jacobsthal;
				inserted_numbers += jacobsthal_diff;
				offset = 0;
			}

			// Step 4: Insert remaining `pend` elements in sequential order
			for (size_t i = 0; i < pend.size(); i++)
			{
				Iterator curr_pend = pend.begin();
				std::advance(curr_pend, i);
				Iterator curr_bound = main.begin();
				std::advance(curr_bound, main.size() - pend.size() + i);
				Iterator idx = std::upper_bound(main.begin(), curr_bound, *curr_pend);
				main.insert(idx, *curr_pend);
			}

			// Step 5: Handle odd number insertion
			if (!oddNumb.empty())
			{
				Iterator odd_pair = oddNumb.begin();
				Iterator idx = std::upper_bound(main.begin(), main.end(), *odd_pair);
				main.insert(idx, *odd_pair);
				oddNumb.erase(odd_pair);
			}
			for (Iterator it = main.begin(); it != main.end(); ++it)
    		    sorting(*it, level);  // Recursively sort each subcontainer
		}
		
		void printContainer(const Container& container) {
			std::cout << "size: " << container.size() << "\n";
			typename Container::const_iterator start, end;
			int pos = 0;
			for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
				start = it->begin();
				end = it->end();
				std::cout << pos++ << ": ";
				for (; start != end; ++start) {
					std::cout << *start << " ";
				}
				std::cout << std::endl;
			}
			std::cout << "\n";
		}
		
		bool comp(const Container &lv, const Container &rv) {
    		return lv.back() < rv.back();
		};
		
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
