/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:25:41 by cofische          #+#    #+#             */
/*   Updated: 2025/01/02 17:25:41 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype> 

using std::string;
using std::cout;
using std::endl; // add a \n at the end of the sentence
using std::cin;
using std::toupper;

void	upperstring(string &str) // Create a copy of the string it is call. Better to pass the string by reference '&' 
{
	for (size_t i = 0; i < str.length(); i++)
		cout << (char)toupper(str[i]); //  It's a good practice to cast it back explicitly in C++98 for better type safety
}

int	main(int ac, char **av)
{
	string str1 = "shhhhh... I think the students are asleep...";
	string str2 = "Damnit";
	string str3 = " ! ";
	string str4 = "Sorry students, I thought this thing was off.";
	string str5 = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (ac == 1)
		cout << str5 << endl;
	else if (ac == 2 && string(av[1]).compare(str1) == 0)
	{
		upperstring(str1);
		cout << "\n";
	}
	else if (ac == 4 && string(av[1]).compare(str2) == 0 && string(av[2]).compare(str3) == 0 && string(av[3]).compare(str4) == 0)
	{
		upperstring(str2);
		upperstring(str3);
		upperstring(str4);
		cout << "\n";
	}
	else
		return (0);
	
	return (0);
}

