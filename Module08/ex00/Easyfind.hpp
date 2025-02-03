/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:20:10 by cofische          #+#    #+#             */
/*   Updated: 2025/02/03 12:14:30 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include "../Colors.hpp"

template <typename T>
void easyfind(T &cont, int x) {
	typename T::iterator it = std::find(cont.begin(), cont.end(), x);

	if (it != cont.end()) {
		std::cout << "First occurrence of " BOLD GREEN << x << RESET " found at position: " BOLD << (it - cont.begin()) << RESET << std::endl;
		return ;
	}
	throw std::runtime_error( BOLD RED "Error: " RESET "no occurence found\n");
}