/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:55:27 by cofische          #+#    #+#             */
/*   Updated: 2025/01/08 10:52:35 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "../../Colors.hpp"

std::string ReplaceLine(std::string &line, std::string &Oldstring, std::string &Newstring) {
	std::string Newline;
	size_t pos = 0;
	size_t found = 0;
	
	if ((found = line.find(Oldstring, pos)) != std::string::npos) {
		Newline += line.substr(pos, found - pos);
		Newline += Newstring;
		pos = found + Oldstring.length();
		Newline += line.substr(pos);
		return (Newline);
	}
	else {
		return (line);
	}
	
}

int main(int ac, char **av)
{
	if (ac < 4) {
		std::cout << "Error, wrong number of parameters. Please restart the program\n1# Filename: ""\n2# Old string: ""\n3# New string: ""\n";
		return (1);
	}
	std::string Filename = av[1];
	std::string OldString = av[2];
	std::string NewString = av[3];
	
	/**/
	std::fstream Oldfile;
	std::ofstream Newfile("NewText.txt");
	
	/*Opening the file with check if open already OR non-existent*/
	Oldfile.open(Filename.c_str()); //using c_str() to convert to const char method
	if (Oldfile.is_open() && Newfile.is_open()) {
			std::string line;
			while (std::getline(Oldfile, line)) {
				std::string temp;
				temp = ReplaceLine(line, OldString, NewString);
				Newfile << temp;
				Newfile << std::endl;
			}
		Oldfile.close();
		Newfile.close();
	}
	else {
		std::cout << BOLD RED << "Error opening file " << RESET << Filename << std::endl;
	}
	return (0);
}