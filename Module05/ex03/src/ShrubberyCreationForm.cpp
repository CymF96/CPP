/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 15:59:39 by cofische          #+#    #+#             */
/*   Updated: 2025-01-22 15:59:39 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &inputTarget) : AForm("ShrubberyCreationForm", 145, 137), target(inputTarget) {};
ShrubberyCreationForm::~ShrubberyCreationForm() {};
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {};
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
};

void drawTree(std::ofstream &file) {
    file << "               ,@@@@@@@,\n";
    file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
    file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
    file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
    file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
    file << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
    file << "       |o|        | |         | |\n";
    file << "       |.|        | |         | |\n";
    file << "   \\\\|_|\\//_/__|_|,\\_//_\\|_|\n\n\n";
	file << "       _-_ \n";
    file << "    /~~   ~~\\ \n";
    file << " /~~         ~~\\ \n";
    file << "{               } \n";
    file << " \\  _-     -_  / \n";
    file << "   ~  \\ //  ~ \n";
    file << "_- -   | | _- _ \n";
    file << "  _ -  | |   -_ \n";
    file << "      // \\\\ \n\n";
}

bool ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (this->getSign() && (executor.getGrade() <= this->getExeGrade())) {
		std::ofstream newfile((target + "_shrubbery").c_str());
		if (newfile.is_open()) {
			drawTree(newfile);
			newfile.close();
		} else 
			std::cout << "Error opening file" << std::endl;
		return true;
	} else
		throw AForm::GradeTooLowException();
};