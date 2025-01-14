/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:32:42 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 18:08:53 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Brain.hpp"

int main() {
	Animal *animalArray[100];
	for (int i = 0; i < 100; i++) {
		if (i < 50) 
			animalArray[i] = new Dog();
		else
			animalArray[i] = new Cat();
	}
	std::cout << std::endl;
	
	for (int i = 0; i < 100; i++) {
		animalArray[i]->makeSound();
	}
	std::cout << std::endl;
	
	for (int i = 0; i < 100; i++)
		delete animalArray[i];
	return 0;
}