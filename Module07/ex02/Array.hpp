/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:57:05 by cofische          #+#    #+#             */
/*   Updated: 2025/01/28 18:05:54 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "../Colors.hpp"

class Array {
	public:
		Array();
		Array(const unsigned int &n);
		~Array();
		Array(const Array &other);
		Array &operator=(const Array &other);
		
		size_t size() const;
};