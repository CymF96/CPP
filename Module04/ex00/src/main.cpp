/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:32:42 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 17:43:43 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

int main() {
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	// const WrongAnimal* animal = new WrongAnimal();
	// const WrongAnimal* cat = new WrongCat();
	
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	std::cout << std::endl;
	
	std::cout << "j type: " << dog->getType() << std::endl;
	std::cout << "i type: " << cat->getType() << " " << std::endl;
	std::cout << "wrongcat: " << wrongcat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	wrongcat->makeSound();
	wrongAnimal->makeSound();
	std::cout << std::endl;
	
    delete wrongAnimal;
    delete wrongcat;
	delete animal;
	delete dog;
	delete cat;
	
	return 0;
}