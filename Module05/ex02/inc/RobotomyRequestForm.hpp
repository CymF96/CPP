/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 15:30:11 by cofische          #+#    #+#             */
/*   Updated: 2025-01-22 15:30:11 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "AForm.hpp"
#include "../../Colors.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(const std::string &inputTarget);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		bool beSign(Bureaucrat &bureaucrat);
		bool execute(Bureaucrat const & executor) const;
	
	private:
		std::string target;
};