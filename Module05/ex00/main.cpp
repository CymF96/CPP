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

#include "Bureaucrat.hpp"

int main(){
	try {
		Bureaucrat Bobby("Bobby", 30);
		Bureaucrat Mandy("Mandy", 1);
		Bureaucrat Tonny("Tonny", 150);
		try {
			Bureaucrat Victoria("Victoria", 0);
		} catch (Bureaucrat::GradeTooHighException &exptH) {
			std::cout << "Error: " << exptH.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException &exptL) {
			std::cout << "Error: " << exptL.what() << std::endl;
		} try {
			Bureaucrat Leon("Leon", 151);
		} catch (Bureaucrat::GradeTooHighException &exptH) {
			std::cout << "Error: " << exptH.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException &exptL) {
			std::cout << "Error: " << exptL.what() << std::endl;
		}

		std::cout << std::endl;
		std::cout << UNDERLINE "Bureaucrats:" RESET << std::endl;
		std::cout << Bobby;
		std::cout << Mandy;
		std::cout << Tonny;
		// std::cout << Victoria << std::endl;
		// std::cout << Leon << std::endl;
		std::cout << std::endl;

		std::cout << UNDERLINE "Decrementing Grade\n" RESET << std::endl;
		std::cout << "Decrementing Bobby's grade by 4:" << std::endl;
		try {
			Bobby.decrementGrade(4);
		} catch (Bureaucrat::GradeTooLowException &exptL) {
			std::cout << "Error: " << exptL.what() << std::endl;
		}
		std::cout << Bobby << std::endl;

		std::cout << "Decrementing Mandy's grade by 3:" << std::endl;
		try {
			Mandy.decrementGrade(3);
		} catch (Bureaucrat::GradeTooLowException &exptL) {
			std::cout << "Error: " << exptL.what() << std::endl;
		}	
		std::cout << Mandy << std::endl;
		std::cout << "Decrementing Tonny's grade by 14:" << std::endl;
		try {
			Tonny.decrementGrade(14);
		} catch (Bureaucrat::GradeTooLowException &exptL) {
			std::cout << "Error: " << exptL.what() << std::endl;
		}
		std::cout << Tonny << std::endl;
		std::cout << std::endl;

		std::cout << UNDERLINE "Incrementting Grade\n" RESET << std::endl;
		std::cout << "Incrementing Bobby's grade by 14:" << std::endl;
		try {
			Bobby.incrementGrade(14);
		} catch (Bureaucrat::GradeTooHighException &exptL) {
			std::cout << "Error: " << exptL.what() << std::endl;
		}	
		std::cout << Bobby << std::endl;
		std::cout << "Incrementing Mandy's grade by 4:" << std::endl;
		try {
			Mandy.incrementGrade(4);
		} catch (Bureaucrat::GradeTooHighException &exptL) {
			std::cout << "Error: " << exptL.what() << std::endl;
		}
		std::cout << Mandy << std::endl;
		std::cout << "Incrementing Tonny's grade by 20:" << std::endl;
		try {
			Tonny.incrementGrade(20);
		} catch (Bureaucrat::GradeTooHighException &exptL) {
			std::cout << "Error: " << exptL.what() << std::endl;
		}
		std::cout << Tonny << std::endl;

	} catch (Bureaucrat::GradeTooHighException &exptH) {
		std::cout << "Error: " << exptH.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &exptL) {
		std::cout << "Error: " << exptL.what() << std::endl;
	}
	return 0;
};