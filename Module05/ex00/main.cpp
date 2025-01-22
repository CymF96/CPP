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
		// Bureaucrat Victoria("Victoria", 0);
		// Bureaucrat Leon("Leon", 151);
		std::cout << std::endl;

		std::cout << Bobby << std::endl;
		std::cout << Mandy << std::endl;
		std::cout << Tonny << std::endl;
		// std::cout << Victoria << std::endl;
		// std::cout << Leon << std::endl;

		std::cout << "Decrementting Grade\n" << std::endl;
		std::cout << "Decrementing Bobby's grade" << std::endl;
		Bobby.decrementGrade(4);
		std::cout << Bobby << std::endl;
		std::cout << "Decrementing Mandyy's grade" << std::endl;
		// Mandy.decrementGrade(3);
		// std::cout << Mandy << std::endl;
		// std::cout << "Decrementing Tonny's grade" << std::endl;
		Tonny.decrementGrade(14);
		std::cout << Tonny << std::endl;

		std::cout << "Incrementting Grade\n" << std::endl;

		std::cout << "Incrementing Bobby's grade" << std::endl;
		Bobby.incrementGrade(14);
		std::cout << Bobby << std::endl;
		std::cout << "Incrementing Mandy's grade" << std::endl;
		Mandy.incrementGrade(4);
		std::cout << Mandy << std::endl;
		// std::cout << "Incrementing Tonny's grade" << std::endl;
		// Tonny.incrementGrade(20);
		// std::cout << Tonny << std::endl;

	} catch (Bureaucrat::GradeTooHighException &exptH) {
		std::cout << "Error: " << exptH.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &exptL) {
		std::cout << "Error: " << exptL.what() << std::endl;
	}
	return 0;
};