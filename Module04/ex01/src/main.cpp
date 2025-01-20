/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:32:42 by cofische          #+#    #+#             */
/*   Updated: 2025/01/20 17:13:34 by cofische         ###   ########.fr       */
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

	/*******************************/
	std::cout << "Creating a Dog object (basic):" << std::endl;
	Dog basic_dog;
	std::cout << "Creating a copy of Dog object (tmp) within a scope:" << std::endl;
	{
		Dog tmp = basic_dog; //Dog tmp(basic);
		tmp.setType("Airplace ✈️");
		std::cout << tmp.getType() << std::endl;
	}
	std::cout << basic_dog.getType() << std::endl;
	std::cout << "End of main scope, basic will now be destroyed.\n" << std::endl;
	/*******************************/

	for (int i = 0; i < 100; i++) {
		animalArray[i]->makeSound();
	}
	std::cout << std::endl;

	for (int i = 0; i < 100; i++)
		delete animalArray[i];
	return 0;
}