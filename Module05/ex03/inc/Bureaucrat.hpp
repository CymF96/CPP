/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:55:06 by cofische          #+#    #+#             */
/*   Updated: 2025/01/22 11:36:50 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "AForm.hpp"
#include "../../Colors.hpp"

class AForm;

class Bureaucrat {
	public:
		Bureaucrat(const std::string &inputName, const int &inputGrade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		
		std::string getName() const;
		int getGrade() const;
		void incrementGrade(const int &inputGrade);
		void decrementGrade(const int &inputGrade);
		void signForm(AForm &form);
		void executeForm(AForm const &form);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
	
	private:
		const std::string name;
		int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);