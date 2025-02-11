/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:34:52 by cofische          #+#    #+#             */
/*   Updated: 2025/02/11 16:39:25 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <sstream>
#include <limits>
#include <deque>
#include <algorithm>
#include "../Colors.hpp"

typedef std::vector<int> vec;
typedef std::deque<int> deq;
typedef vec::iterator itv;
typedef deq::iterator itd;
typedef std::deque<vec> ddeq;

class Pmerge {
	public:
		static void sorted(char ** input, size_t size);
		static void generateSequence(char ** input, size_t size);
		static void pairing(ddeq &inputSequence);
		// static void printList();
		// static itl binarySearch(int key);
		// static void binaryInsert(int key);

		class PmergeError : public std::exception {
			private:
				const char* message;
			public:
				PmergeError(const char *msg);
				virtual const char* what() const throw();
		};
		
	private:
		Pmerge();
		~Pmerge();
		Pmerge(const Pmerge &other);
		Pmerge &operator=(const Pmerge &other);
};

int convertInt(char *nbr);
void convertToList();