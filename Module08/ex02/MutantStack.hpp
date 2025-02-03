/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:06:10 by cofische          #+#    #+#             */
/*   Updated: 2025/02/03 18:55:56 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include "../Colors.hpp"

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	
	public:
		MutantStack() : std::stack<T, Container>() {};
		~MutantStack() {};
		MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {};
		MutantStack &operator=(const MutantStack &other) {
			if (this != &other) {
				std::stack<T, Container>::operator=(other);	
			}
			return *this;
		};
		
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		
		iterator begin() { return this->c.begin(); };
		iterator end() { return this->c.end(); };
		const_iterator begin() const { return this->c.begin(); };
		const_iterator end() const { return this->c.end(); };
};

