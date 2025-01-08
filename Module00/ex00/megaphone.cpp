/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:25:41 by cofische          #+#    #+#             */
/*   Updated: 2025/01/08 17:49:33 by cofische         ###   ########.fr       */
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
	std::string str1 = "shhhhh... I think the students are asleep...";
	std::string str2 = "Damnit";
	std::string str3 = " ! ";
	std::string str4 = "Sorry students, I thought this thing was off.";
	std::string str5 = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (ac == 1)
		std::cout << str5 << std::endl;
	else if (ac == 2 && std::string(av[1]).compare(str1) == 0)
	{
		upperstring(str1);
		std::cout << "\n";
	}
	else if (ac == 4 && std::string(av[1]).compare(str2) == 0 && std::string(av[2]).compare(str3) == 0 && std::string(av[3]).compare(str4) == 0)
	{
		upperstring(str2);
		upperstring(str3);
		upperstring(str4);
		std::cout << "\n";
	}
	else
		return (0);
	
	return (0);
}

