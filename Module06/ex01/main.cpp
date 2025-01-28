/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:08:56 by cofische          #+#    #+#             */
/*   Updated: 2025/01/28 11:45:06 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {

	Data *dataPtr = new Data;
	dataPtr->type = "computer";
	dataPtr->size = 246;
	dataPtr->category = 'b';
	dataPtr->active = true;
	
	Data *dataPtrTest = new Data;
	dataPtrTest->type = "washing_machine";
	dataPtrTest->size = 540;
	dataPtrTest->category = 'd';
	dataPtrTest->active = false;
	
	uintptr_t dataRaw = Serializer::serialize(dataPtr);
	Data *dataPtr1 = Serializer::deserialize(dataRaw);
	
	std::cout << "Address of dataPtr: " << GREEN << dataPtr << RESET << std::endl;
	std::cout << "Address of dataRaw: " << GREEN << &dataRaw << RESET << std::endl;
	std::cout << "Address of dataPtr1: " << GREEN << dataPtr1 << RESET << std::endl;
	std::cout << std::endl;
	
	std::cout << BOLD "POINTER COMPARISON AFTER REINTERPRET_CAST" RESET << std::endl;
	std::cout << "dataPtr->type: " << BLUE << dataPtr->type << RESET << std::endl;
	std::cout << "dataPtr->size: " << BLUE << dataPtr->size << RESET << std::endl;
	std::cout << "dataPtr->category: " << BLUE << dataPtr->category << RESET << std::endl;
	std::cout << "dataPtr->active: " << BLUE << dataPtr->active << RESET "\n" << std::endl;
	std::cout << "dataPtr1->type: " << CYAN << dataPtr1->type << RESET << std::endl;
	std::cout << "dataPtr1->size: " << CYAN << dataPtr1->size << RESET << std::endl;
	std::cout << "dataPtr1->category: " << CYAN << dataPtr1->category << RESET << std::endl;
	std::cout << "dataPtr1->active: " << CYAN << dataPtr1->active << RESET "\n" << std::endl;
	
	std::cout << BOLD "TESTING DIRECT REINTERPRET_CAST WITHOUT RAW CONVERSION" RESET << std::endl;
	Data *dataPtrTest1 = reinterpret_cast<Data*>(dataPtrTest);
	std::cout << "Address of dataPtrTest: " << GREEN << dataPtrTest << RESET << std::endl;
	std::cout << "Address of dataPtrTest1: " << GREEN << dataPtrTest1 << RESET "\n" << std::endl;
	std::cout << BOLD "POINTER COMPARISON AFTER REINTERPRET_CAST" RESET << std::endl;
	std::cout << "dataPtrTest->type: " << BLUE << dataPtrTest->type << RESET << std::endl;
	std::cout << "dataPtrTest->size: " << BLUE << dataPtrTest->size << RESET << std::endl;
	std::cout << "dataPtrTest->category: " << BLUE << dataPtrTest->category << RESET << std::endl;
	std::cout << "dataPtrTest->active: " << BLUE << dataPtrTest->active << RESET "\n" << std::endl;
	std::cout << "dataPtrTest1->type: " << CYAN << dataPtrTest1->type << RESET << std::endl;
	std::cout << "dataPtrTest1->size: " << CYAN << dataPtrTest1->size << RESET << std::endl;
	std::cout << "dataPtrTest1->category: " << CYAN << dataPtrTest1->category << RESET << std::endl;
	std::cout << "dataPtrTest1->active: " << CYAN << dataPtrTest1->active << RESET "\n" << std::endl;
	
	char value = '5';
	char *ptrValue = &value;
	int *numValue = reinterpret_cast<int*>(ptrValue);
	
	std::cout << "Address of ptrValue: " << GREEN << static_cast<void*>(ptrValue) << RESET << std::endl;
	std::cout << "Address of numValue: " << GREEN << numValue << RESET << std::endl;
	std::cout << "Value of ptrValue: " << BLUE << *ptrValue << RESET << std::endl;
	std::cout << "Value of numValue: " << BLUE << *numValue << RESET << std::endl;
	*numValue = 10;
	std::cout << "Value of ptrValue after reassignment: " << CYAN << *ptrValue << RESET << std::endl;
	std::cout << "Value of numValue after reassignment: " << CYAN << *numValue << RESET << std::endl;

	return 0;

}