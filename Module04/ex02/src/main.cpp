/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:32:42 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 18:30:39 by cofische         ###   ########.fr       */
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
	

	// delete animal;
	delete dog;
	delete cat;
	
	return 0;
}