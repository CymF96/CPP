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
#include "../inc/Form.hpp"

int main() {
	try {
		Bureaucrat Bobby("Bobby", 30);
		Bureaucrat Mandy("Mandy", 122);
		Form B27("B27", 32, 60);
		Form B28("B28", 100, 80);
		std::cout << std::endl;
		std::cout << UNDERLINE "Bureaucrats:\n" RESET;
		std::cout << Bobby;
		std::cout << Mandy;
		std::cout << UNDERLINE "\nForms:\n" RESET;
		std::cout << B27 << std::endl;
		std::cout << B28 << std::endl;

		std::cout << UNDERLINE "Sign protocol test:" RESET << std::endl;
	 	try {
			Bobby.signForm(B28);
		} catch (Form::GradeTooLowException &exptL) {
			std::cout << BOLD BLUE << Bobby.getName() << RESET << " coudn't signed the form " << BOLD BLUE << B28.getName() << RESET " because " << exptL.what2() << std::endl;
		}
		if (B28.getSign())
			std::cout << B28.getName() << " is now " << BOLD GREEN << "signed" << RESET << std::endl;
		else
			std::cout << B28.getName() << " is " << BOLD RED << "not signed" << RESET << std::endl;
		std::cout << std::endl;
		try {
			Mandy.signForm(B27);
		} catch (Form::GradeTooLowException &exptL) {
			std::cout << BOLD BLUE << Mandy.getName() << RESET << " coudn't signed the form " << BOLD BLUE << B27.getName() << RESET " because " << exptL.what2() << std::endl;
		}
		if (B27.getSign())
			std::cout << B27.getName() << " is now " << BOLD GREEN << "signed" << RESET << std::endl;
		else
			std::cout << B27.getName() << " is " << BOLD RED << "not signed" << RESET << std::endl;
		std::cout << std::endl;
		try {
			Bobby.signForm(B27);
		} catch (Form::GradeTooLowException &exptL) {
			std::cout << BOLD BLUE << Bobby.getName() << RESET << " coudn't signed the form " << BOLD BLUE << B27.getName() << RESET " because " << exptL.what2() << std::endl;
		}
		if (B27.getSign())
			std::cout << B27.getName() << " is now " << BOLD GREEN << "signed" << RESET << std::endl;
		else
			std::cout << B27.getName() << " is " << BOLD RED << "not signed" << RESET << std::endl;
		std::cout << std::endl;

	} catch (Bureaucrat::GradeTooHighException &exptH) {
		std::cout << "Error: " << exptH.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &exptL) {
		std::cout << "Error: " << exptL.what() << std::endl;
	} catch (Form::GradeTooHighException &exptH) {
		std::cout << "Error: " << exptH.what() << std::endl;
	} catch (Form::GradeTooLowException &exptL) {
		std::cout << "Error: " << exptL.what() << std::endl;
	}
	return 0;
};