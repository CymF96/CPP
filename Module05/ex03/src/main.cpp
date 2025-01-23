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
#include "../inc/Intern.hpp"

int main() {
	try {
		Bureaucrat Bobby("Bobby", 30);
		Bureaucrat Mandy("Mandy", 150);
		Bureaucrat Boss("Boss", 1);

		std::cout << BOLD << "\n--------- Welcome to BORING ADMIN LTD ----------\n\n"
				  << RESET << UNDERLINE << "See below our premium Bureaucrats:" << RESET << std::endl;
		std::cout << Bobby << std::endl;
		std::cout << Mandy << std::endl;
		std::cout << UNDERLINE << "The Boss:" << RESET << std::endl;
		std::cout << Boss << std::endl;
		std::cout << "and some intern apparently:" << std::endl;
		Intern RandomIntern1;
		AForm* Repeat, *Sorry, *Tree, *WhoCares;
		std::cout << std::endl;
		
		std::cout << BOLD << "A normal day at BORING ADMIN LTD...\n" << RESET << std::endl;

		std::cout << "--6am--\nthe Intern making some form for the day:" << std::endl;
		Sorry = RandomIntern1.makeForm("Presidential", "Bobby");
		Repeat = RandomIntern1.makeForm("Robotomy", "Boss"); 
		Tree = RandomIntern1.makeForm("Shrubbery", "Mandy");

		try {
			WhoCares = RandomIntern1.makeForm("Make coffee", "All Bureaucrats");
		} catch (const Intern::NoFormFound &exptI) {
			std::cout << "Error: " << exptI.what() << std::endl; 
		}

		std::cout << "--6:30am--\nThe forms are now available thanks to ... what's his name again?...\n" << std::endl;
		std::cout << UNDERLINE "Available forms:\n" RESET;
		std::cout << *Repeat << std::endl; 
		std::cout << *Tree << std::endl; 
		std::cout << *Sorry << std::endl; 

		std::cout << "--10am--\nBureaucrats arrive and start doing stuff" << std::endl;
		try {
			std::cout << "Bobby was asked by Mandy to sign the Robotomy Form and execute it." << std::endl;
			Bobby.signForm(*Repeat);
			if (Repeat->getSign())
				std::cout << Repeat->getName() << " is now " << BOLD GREEN << "signed" << RESET << std::endl;
			Bobby.executeForm(*Repeat);
			std::cout << std::endl;
		} catch (const Bureaucrat::GradeTooLowException &exptL) {
			std::cout << "Error: Bobby couldn't sign the form: " << exptL.what() << std::endl;
		} catch (const AForm::GradeTooLowException &exptL) {
			std::cout << "Error: Bobby couldn't execute the form: " << exptL.what() << std::endl;
		}

		try {
			std::cout << "Then Mandy signed the Shrubbery Form and executed it." << std::endl;
			Mandy.signForm(*Tree);
			if (Tree->getSign())
				std::cout << Tree->getName() << " is now " << BOLD GREEN << "signed" << RESET << std::endl;
			Mandy.executeForm(*Tree);
			std::cout << std::endl;
		} catch (const Bureaucrat::GradeTooLowException &exptL) {
			std::cout << "Error: Mandy couldn't sign the form: " << exptL.what() << std::endl;
		} catch (const AForm::GradeTooLowException &exptL) {
			std::cout << "Error: Mandy couldn't execute the form: " << exptL.what() << std::endl;
		}

		try {
			std::cout << "Bobby noticed an error in his form and tried to sign the Pardon Form for his mistake." << std::endl;
			Bobby.signForm(*Sorry);
			std::cout << std::endl;
		} catch (const Bureaucrat::GradeTooLowException &exptL) {
			std::cout << "Error: Bobby couldn't sign the form: " << exptL.what() << std::endl;
		}
		std::cout << "--1pm--\nThe Boss has arrived and start cleaning Bureacrats' mess" << std::endl;
		try {
			std::cout << "The Boss decided to use his Presidential Pardon." << std::endl;
			Boss.signForm(*Sorry);
			if (Sorry->getSign())
				std::cout << Sorry->getName() << " is now " << BOLD GREEN << "signed" << RESET << std::endl;
			Boss.executeForm(*Sorry);
			std::cout << std::endl;
		} catch (const Bureaucrat::GradeTooHighException &exptH) {
			std::cout << "Error: Boss couldn't sign the form: " << exptH.what() << std::endl;
		} catch (const AForm::GradeTooLowException &exptL) {
			std::cout << "Error: Boss couldn't execute the form: " << exptL.what() << std::endl;
		}

		delete Tree;
		delete Repeat;
		delete Sorry;

		std::cout 	<< "--4pm--\nEnd of day (except for intern that needs to clean the Boss' office)\n"
					<< BOLD << "\n--------- Goodbye ----------\n\n" << RESET;

	} catch (const Bureaucrat::GradeTooHighException &exptH) {
		std::cout << "Error: " << exptH.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &exptL) {
		std::cout << "Error: " << exptL.what() << std::endl;
	} catch (const AForm::GradeTooHighException &exptH) {
		std::cout << "Error: " << exptH.what() << std::endl;
	} catch (const AForm::GradeTooLowException &exptL) {
		std::cout << "Error: " << exptL.what() << std::endl;
	}
	return 0;
}