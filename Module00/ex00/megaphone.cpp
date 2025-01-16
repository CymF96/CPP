/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:25:41 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 15:00:09 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

void	upperstring(std::string &str) // Create a copy of the string it is call. Better to pass the string by reference '&' 
{
	for (size_t i = 0; i < str.length(); i++)
		std::cout << (char)toupper(str[i]); //  It's a good practice to cast it back explicitly in C++98 for better type safety
}

int	main(int ac, char **av)
{
	std::string str5 = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (ac == 1)
		std::cout << str5 << std::endl;
	else {
	
		for (int i = 1; av[i] ; i++) {
			std::string temp = av[i];
			upperstring(temp);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}

