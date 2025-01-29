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

#pragma once
#include <iostream>
#include <exception>
#include "../Colors.hpp"

template <typename T>
class Array {
	public:
	/***************************************************************/
	//					CONSTRUCTORS
	/***************************************************************/

		Array() : arrSize(0) {
			std::cout << BLUE "Default constructor" RESET << std::endl;
			array = new T[arrSize];
			for (unsigned int i = 0; i < arrSize; i++)
				array[i] = 0;
		}
		Array(const unsigned int n) : arrSize(n) {
			std::cout << CYAN "Default constructor with parameter" RESET << std::endl;
			array = new T[arrSize]; 
			for (unsigned int i = 0; i < arrSize; i++)
				array[i] = 0;
		}
		~Array()  {
			std::cout << RED "Default destructor" RESET << std::endl;
			if (array)
				delete [] array;
		}
		Array(const Array &other) : array(new T[other.arrSize]), arrSize(other.arrSize) {
			std::cout << GREEN "Copy constructor" RESET << std::endl;
			for (unsigned int i = 0; i < arrSize ; i++)
				array[i] = other.array[i];
		}

	/***************************************************************/
	//					OPERATOR OVERLOAD
	/***************************************************************/

		Array &operator=(const Array &other)  {
			if (this != *other) {
				delete [] this->array;
				arrSize = other.arrSize;
            	array = new T[arrSize];
            	for (unsigned int i = 0; i < arrSize; ++i) {
               		array[i] = other.array[i];
				}
			}
			return *this;
		}

		T &operator[](unsigned int index) {
			if (index >= this->arrSize)
				throw std::out_of_range(BOLD RED "Error, index out of bound" RESET);
			return this->array[index];
		}

		const T &operator[](unsigned int index) const {
			if (index >= this->arrSize)
				throw std::out_of_range(BOLD RED "Error, index out of bound" RESET);
			return this->array[index];
		}
		
	/***************************************************************/
	//					METHODS
	/***************************************************************/

		unsigned int size() const {
			return arrSize;
		}

		T *getArray() {
			return array; 
		}

	private:
		T *array;
		unsigned int arrSize;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &array) {
	if (array.size() == 0) {
		os << "Array is empty" << std::endl;
		return os;
	} else if (array.size() >= 5) {
		for (unsigned int i = 0; i < 5; i++)
			os << "Array[" << i << "] = " << array[i] << std::endl;
		return os;
	} else {
		for (unsigned int i = 0; i < array.size(); i++)
			os << "Array[" << i << "] = " << array[i] << std::endl;
		return os;
	}
};