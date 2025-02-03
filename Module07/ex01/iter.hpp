/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:48:32 by cofische          #+#    #+#             */
/*   Updated: 2025/02/03 11:06:10 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>
#include "../Colors.hpp"

template <typename Titer>
void iter(Titer *arr, size_t len, void (*f)(Titer &)) {
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
};

template <typename Titer>
void iter(Titer *arr, size_t len, void (*f)(Titer const &)) {
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
};

template <typename T>
void printIter(T var) {
	std::cout << var << std::endl;
}

void multiply(int &a) {
	a *= a;
}

void upperchar(std::string &str) {
	for (int i = 0; i < str[i]; i++)
		str[i] = (char)toupper(str[i]);
}

void formating(double &x) {
	x = std::floor(x * 10.0 + 0.5) / 10.0;
};