/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:42:55 by cofische          #+#    #+#             */
/*   Updated: 2025/02/03 12:23:31 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

int main() {
	
	/******************************/
	/*****TEST WITH INTEGER VEC****/
	/******************************/
	std::cout << INVERSE BOLD "\n/******************************/\n/*****TEST WITH INTEGER VEC****/\n/******************************/\n" RESET << std::endl;
	std::vector<int> vec;
	int pos = 0;
	int x = 2;
	
	for (int i = 0; i < 100; i++)
		vec.push_back(x += 2);

	std::vector<int>::iterator it;
	
	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << BOLD BLUE << pos++ << ": " RESET << *it << " // ";
	std::cout << std::endl;
	
	int w = 62;
	int y = 8;
	int z = 57;
	try {
		easyfind(vec, y);
		easyfind(vec, w);
		easyfind(vec, z);
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	/******************************/
	/*****TEST WITH CHAR VEC*******/
	/******************************/
	std::cout << INVERSE BOLD "\n/******************************/\n/*****TEST WITH CHAR VEC*******/\n/******************************/\n" RESET << std::endl;
	std::vector<char> vecChar;
	pos = 0;
	char a = 'a';
	
	for (int i = 0; i < 14; i++)
		vecChar.push_back(a += 2);

	std::vector<char>::iterator itChar;
	
	for (itChar = vecChar.begin(); itChar != vecChar.end(); ++itChar)
		std::cout << BOLD BLUE << pos++ << ": " RESET << *itChar << " // ";
	std::cout << std::endl;
	
	char c = 'c';
	char k = 'k';
	char Z = 'Z';
	try {
		easyfind(vecChar, c);
		easyfind(vecChar, k);
		easyfind(vecChar, Z);
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	return 0;
}