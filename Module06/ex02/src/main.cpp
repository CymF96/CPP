/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:52:31 by cofische          #+#    #+#             */
/*   Updated: 2025/01/28 13:52:34 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utility.hpp"

int main() {

	std::srand(std::time(0));
	
	Base *ptr1 = generate();
	Base *ptr2 = generate();
	Base *ptr3 = generate();
	Base &refPtr1 = *ptr1;
	Base &refPtr2 = *ptr2;
	Base &refPtr3 = *ptr3;
	
	identify(ptr1);
	identify(ptr2);
	identify(ptr3);
	
	identify(refPtr1);
	identify(refPtr2);
	identify(refPtr3);
	
	delete ptr1;
	delete ptr2;
	delete ptr3;
	
	return 0;
}