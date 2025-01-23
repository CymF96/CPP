/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-23 10:43:55 by cofische          #+#    #+#             */
/*   Updated: 2025-01-23 10:43:55 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "AForm.hpp"
#include "../../Colors.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);

		AForm *makeForm(const std::string &formName, const std::string &inputTarget);

		class NoFormFound : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

AForm *createShrubbery(const std::string &target);
AForm *createRobotomy(const std::string &target);
AForm *createPresidential(const std::string &target);