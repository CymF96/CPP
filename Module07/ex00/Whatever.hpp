/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:03:22 by cofische          #+#    #+#             */
/*   Updated: 2025/01/28 16:40:30 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../Colors.hpp"

template <typename Tswap>
void swap(Tswap &var1, Tswap &var2) {
	Tswap temp = var1;
	var1 = var2;
	var2 = temp;
};

template <typename Tmax>
Tmax max(Tmax var1, Tmax var2) {
	return (var2 >= var1 ? var2 : var1);
};

template <typename Tmin>
Tmin min(Tmin var1, Tmin var2) {
	return (var2 <= var1 ? var2 : var1);
};
