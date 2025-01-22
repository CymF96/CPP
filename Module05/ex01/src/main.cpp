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

int main(){
	try {
		Bureaucrat Bobby("Bobby", 30);
		Bureaucrat Mandy("Mandy", 122);
		Form B27("B27", 12, 60);
		Form B28("B28", 100, 80);
		// Form B29("B28", 0, 180);

		std::cout << std::endl;
		std::cout << "Bureaucrats: \n";
		std::cout << Bobby << std::endl;
		std::cout << Mandy << std::endl;
		std::cout << "Forms: \n";
		std::cout << B27 << std::endl;
		std::cout << B28 << std::endl;
		// std::cout << B29 << std::endl;
		std::cout << std::endl;

		std::cout << "Sign protocol test: " << std::endl;
		Bobby.signForm(B28);
		std::cout << std::endl;
		std::cout << B28 << std::endl;
		Mandy.signForm(B27);
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