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

int main(){
	try {
		Bureaucrat Bobby("Bobby", 30);
		Bureaucrat Mandy("Mandy", 122);
	} catch {
		
	}
	return 0;
};