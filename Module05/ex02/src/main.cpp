/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:23:13 by cofische          #+#    #+#             */
/*   Updated: 2025/01/22 11:26:11 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main() {
	try {
		Bureaucrat Bobby("Bobby", 30);
		Bureaucrat Mandy("Mandy", 70);
		Bureaucrat Tonny("Tonny", 150);
		Bureaucrat Boss("Boss", 1);
		RobotomyRequestForm Repeat("Mandy");
		ShrubberyCreationForm Tree("Boss");
		RobotomyRequestForm Repeat2("Tonny");
		PresidentialPardonForm Sorry("Bobby");

		std::cout << BOLD << "\n--------- Welcome to BORING ADMIN LTD ----------\n\n"
				  << RESET << UNDERLINE << "See below our premium Bureaucrats:" << RESET << std::endl;
		std::cout << Bobby;
		std::cout << Tonny;
		std::cout << Mandy << std::endl;
		std::cout << UNDERLINE << "The Boss:" << RESET << std::endl;
		std::cout << Boss << std::endl;
		std::cout << UNDERLINE << "The available forms:" << RESET << std::endl;
		std::cout << Repeat << std::endl;
		std::cout << Repeat2 << std::endl;
		std::cout << Tree << std::endl;
		std::cout << Sorry << std::endl;

		std::cout << BOLD << "A normal day at BORING ADMIN LTD...\n"
				  << RESET << std::endl;

		std::cout << "Bobby wants to Robotomy Mandy. They're too slow." << std::endl;
		try {
			Bobby.signForm(Repeat);
		} catch (const AForm::GradeTooLowException& exptL) {
			std::cout << BOLD BLUE << Bobby.getName() << RESET << " couldn't sign the form " << BOLD BLUE << Repeat.getName() << RESET << " because " << exptL.what2() << std::endl; 
		} 
		if (Repeat.getSign())
		std::cout << Repeat.getName() << " is now " << BOLD GREEN << "signed" << RESET << std::endl;
		try {
			Bobby.executeForm(Repeat);
			std::cout << std::endl;
		} catch (const AForm::GradeTooLowException& exptL) {
			std::cout << BOLD BLUE << Bobby.getName() << RESET << " couldn't execute the form " << BOLD BLUE << Repeat.getName() << RESET << " because " << exptL.what3() << std::endl; 
		}

		std::cout << "Then Mandy signed the Shrubbery Form and executed it as a Robot." << std::endl;
		try {
			Mandy.signForm(Tree);
		} catch (const AForm::GradeTooLowException& exptL) {
			std::cout << BOLD BLUE << Mandy.getName() << RESET << " couldn't sign the form " << BOLD BLUE << Tree.getName() << RESET << " because " << exptL.what2() << std::endl; 
		} 
		if (Tree.getSign())
		std::cout << Tree.getName() << " is now " << BOLD GREEN << "signed" << RESET << std::endl;
		try {
			Mandy.executeForm(Tree);
			std::cout << std::endl;
		} catch (const AForm::GradeTooLowException& exptL) {
			std::cout << BOLD BLUE << Mandy.getName() << RESET << " couldn't execute the form " << BOLD BLUE << Tree.getName() << RESET << " because " << exptL.what3() << std::endl; 
		}

		std::cout << "Mandy wants to optimise Tonny using the RobotomizeRequestForm" << std::endl;
		try {
			Mandy.signForm(Repeat2);
		} catch (const AForm::GradeTooLowException& exptL) {
			std::cout << BOLD BLUE << Mandy.getName() << RESET << " couldn't sign the form " << BOLD BLUE << Repeat2.getName() << RESET << " because " << exptL.what2() << std::endl; 
		} 
		if (Repeat2.getSign())
			std::cout << Repeat2.getName() << " is now " << BOLD GREEN << "signed" << RESET << std::endl;
		try {
			Mandy.executeForm(Repeat2);
			std::cout << std::endl;
		} catch (const AForm::GradeTooLowException& exptL) {
			std::cout << BOLD BLUE << Mandy.getName() << RESET << " couldn't execute the form " << BOLD BLUE << Repeat2.getName() << RESET << " because " << exptL.what3() << std::endl; 
		}

		std::cout << "\nBobby noticed an error in his form and tried to sign the Pardon Form for his mistake." << std::endl;
		try {
			Bobby.signForm(Sorry);
			std::cout << std::endl;
		} catch (const AForm::GradeTooLowException& exptL) {
			std::cout << BOLD BLUE << Bobby.getName() << RESET << " couldn't sign the form " << BOLD BLUE << Sorry.getName() << RESET << " because " << exptL.what2() << std::endl; 
		}
		std::cout << "\nThe Boss decided to use their Presidential Pardon." << std::endl;
		try {
			Boss.signForm(Sorry);
		} catch (const AForm::GradeTooLowException& exptL) {
			std::cout << BOLD BLUE << Boss.getName() << RESET << " couldn't sign the form " << BOLD BLUE << Sorry.getName() << RESET << " because " << exptL.what2() << std::endl; 
		} 
		if (Sorry.getSign())
			std::cout << Sorry.getName() << " is now " << BOLD GREEN << "signed" << RESET << std::endl;
		try {
			Boss.executeForm(Sorry);
		} catch (const AForm::GradeTooLowException& exptL) {
			std::cout << BOLD BLUE << Boss.getName() << RESET << " couldn't execute the form " << BOLD BLUE << Sorry.getName() << RESET << " because " << exptL.what3() << std::endl; 
		} 

		std::cout << "\nAnd it is another end of day full of adventures at BORING ADMIN LTD...\n" << std::endl;

	} catch (const Bureaucrat::GradeTooHighException& exptH) {
		std::cout << "Error: " << exptH.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& exptL) {
		std::cout << "Error: " << exptL.what() << std::endl;
	} catch (const AForm::GradeTooHighException& exptH) {
		std::cout << "Error: " << exptH.what() << std::endl;
	} catch (const AForm::GradeTooLowException& exptL) {
		std::cout << "Error: " << exptL.what() << std::endl;
	}
	
	return 0;
}