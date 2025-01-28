/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:02:23 by cofische          #+#    #+#             */
/*   Updated: 2025/01/28 17:54:34 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	int array[] = {1, 2, 3};
	size_t lenghtArray = sizeof(array)/sizeof(array[0]);
	
	std::cout << BOLD BLUE "Original Int Array" RESET << std::endl; 
	iter(array, lenghtArray, &printIter);
	iter(array, lenghtArray, &multiply);
	std::cout << BOLD GREEN "New Int Array after iter: " RESET << std::endl;
	iter(array, lenghtArray, &printIter);
	std::cout << std::endl;
	
	std::string strArray[] = {"hello", "how", "are" , "you?"};
	size_t lenStr = sizeof(strArray) / sizeof(strArray[0]);
	
	std::cout << BOLD BLUE "Original string Array" RESET << std::endl; 
	iter(strArray, lenStr, &printIter);
	iter(strArray, lenStr, &upperchar);
	std::cout << BOLD GREEN "New string after iter: " RESET << std::endl;
	iter(strArray, lenStr, &printIter);
	std::cout << std::endl;
	
	double arrayD[] = {146.256, -258.765489, 3.1415926535};
	size_t lenArrayD = sizeof(arrayD)/sizeof(arrayD[0]);
	
	std::cout << BOLD BLUE "Original Double Array" RESET << std::endl; 
	iter(arrayD, lenArrayD, &printIter);
	iter(arrayD, lenArrayD, &formating);
	std::cout << BOLD GREEN "New Double Array after iter: " RESET << std::endl;
	iter(arrayD, lenArrayD, &printIter);
	std::cout << std::endl;
	
	return 0;
}