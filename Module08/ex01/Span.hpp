/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:25:04 by cofische          #+#    #+#             */
/*   Updated: 2025/02/03 14:50:27 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "../Colors.hpp"

class Span {
	public:
		Span(const unsigned int inputN);
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);
		
		std::vector<int> intVector;
		
		void addNumber(unsigned int inputNum);
		void addManyNumber(Span &v);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		unsigned int getN();
		
	private:
		unsigned int N;		
};

std::ostream &operator<<(std::ostream &os, Span &Span);