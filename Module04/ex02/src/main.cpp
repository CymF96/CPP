/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:32:42 by cofische          #+#    #+#             */
/*   Updated: 2025/01/20 17:05:48 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Brain.hpp"

int main() {
	// const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	
	std::cout << "type: " << dog->getType() << std::endl;
	std::cout << "type: " << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	// animal->makeSound();
	std::cout << std::endl;
	
	/*******************************/
	// std::cout << "Creating a Dog object (basic):" << std::endl;
	// Dog basic_dog;
	// std::cout << "\nCreating a copy of Dog object (tmp):" << std::endl;
	// {
	// 	Dog tmp = basic_dog; //Dog tmp(basic);
	// 	tmp.setType("Airplace ✈️");
	// 	std::cout << tmp.getType() << std::endl;
	// }
	// std::cout << basic_dog.getType() << std::endl;
	// std::cout << "\nEnd of main scope, basic will now be destroyed." << std::endl;
	// /*******************************/

	// delete animal;
	delete dog;
	delete cat;
	
	return 0;
}