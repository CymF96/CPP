#include <iostream>
#include <fstream>
#include <string>
#include "../Colors.hpp"

std::string ReplaceLine(std::string &line, std::string &Oldstring, std::string &Newstring) {
	std::string Newline;
	size_t pos = 0;
	size_t found = 0;
	
	while ((found = line.find(Oldstring, pos)) != std::string::npos) {
		Newline += line.substr(pos, found - pos);
		Newline += Newstring;
		pos = found + Oldstring.length();
	}
	Newline += line.substr(pos);
	return Newline;
}

int main(int ac, char **av) {
	if (ac < 4) {
		std::cout << "Error, wrong number of parameters. Please restart the program\n1# Filename: \"<filename>\"\n2# Old string: \"<s1>\"\n3# New string: \"<s2>\"\n";
		return 1;
	}

	std::string Filename = av[1];
	std::string OldString = av[2];
	std::string NewString = av[3];
	std::ofstream Newfile((Filename + ".replace").c_str());
	std::ifstream Oldfile((Filename).c_str());
	
	if (Oldfile.is_open() && Newfile.is_open()) {
		std::string line;
		while (std::getline(Oldfile, line)) {
			std::string temp = ReplaceLine(line, OldString, NewString);
			Newfile << temp << std::endl;
		}
		Oldfile.close();
		Newfile.close();
	} else {
		std::cout << BOLD RED << "Error opening file " << RESET << Filename << std::endl;
	}
	
	return 0;
}