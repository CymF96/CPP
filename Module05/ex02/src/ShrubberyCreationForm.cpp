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

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &inputTarget) : AForm("PresidentialPardonForm", 145, 137), target(inputTarget) {};
ShrubberyCreationForm::~ShrubberyCreationForm() {};
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {};
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
};

bool ShrubberyCreationForm::beSign(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() >= this->getSignGrade())
		throw Bureaucrat::GradeTooLowException();
	else
		this->setSign();
	return (this->getSign());
};

void drawTree() {
	std::cout << R"(
		       ,@@@@@@@,
       ,,,.   ,@@@@@@/@@,  .oo8888o.
    ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o
   ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'
   %&&%&%&/%&&%@@\@@/ /@@@88888\88888'
   %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'
   `&%\ ` /%&'    |.|        \ '|8'
       |o|        | |         | |
       |.|        | |         | |
	 \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_)" 
	<< std::endl;
}

bool ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (this->getSign() && (executor.getGrade() <= this->getExeGrade())) {
		
		return true;
	} else
		throw Bureaucrat::GradeTooLowException();
	
};