/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:25:16 by cofische          #+#    #+#             */
/*   Updated: 2025/02/03 14:53:39 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(const unsigned int inputN) : N(inputN) {}
Span::~Span() {}
Span::Span(const Span &other) : N(other.N) {}
Span &Span::operator=(const Span &other) {
	if (this != &other)
		N = other.N;
	return *this;
}

unsigned int Span::getN() { return N; };

void Span::addNumber(unsigned int inputNum) {
	if (intVector.size() < N)
		intVector.push_back(inputNum);
	else
		throw std::out_of_range("Unbale to add new number --> Limit of container reach\n");
};

void Span::addManyNumber(Span &v) {
	std::vector<int>::iterator begin = v.intVector.begin();
	std::vector<int>::iterator end = v.intVector.end();
	if (this->intVector.size() + (end - begin) < N)
		this->intVector.insert(this->intVector.end(), begin, end);
	else
		throw std::out_of_range("Unable to add range of numbers --> Limit of container reach\n");
};

unsigned int Span::shortestSpan() {
	std::vector<int>::iterator it;
	if (!intVector.empty() && intVector.size() > 1) {
		
		std::sort(intVector.begin(), intVector.end());
		for (it = intVector.begin(); it != intVector.end(); ++it) {
			if (*it != *(it + 1))
				return (*(it + 1) - *it);
		}
		return (0);		
	
	} else
		throw std::invalid_argument("Size of container is too small\n");
};

unsigned int Span::longestSpan() {
	if (!intVector.empty() && intVector.size() > 1) {
		std::sort(intVector.begin(), intVector.end());
		return (intVector.back() - intVector.front());
		
	} else
		throw std::invalid_argument("Size of container is too small\n");
};

std::ostream &operator<<(std::ostream &os, Span &Span) {
	std::vector<int>::iterator it;
	int pos = 0;
	if (!Span.intVector.empty()) {
		for (it = Span.intVector.begin(); it != Span.intVector.end(); ++it)
			os << BOLD BLUE << pos++ << RESET ": " << *it << " // ";
		os << BOLD GREEN "\nSize of container: " RESET << Span.intVector.size() << std::endl;
		os << std::endl;
	} else
		os << "Container is empty" << std::endl;
	return os;
};
