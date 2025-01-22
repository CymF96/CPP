/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 12:42:42 by cofische          #+#    #+#             */
/*   Updated: 2025-01-22 12:42:42 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "../../Colors.hpp"

class Bureaucrat;

class Form {
	public:
		Form(const std::string &inputName, const int &inputSignGrade, const int &inputExeGrade);
		~Form();
		Form(const Form &other);
		Form &operator=(const Form &other);

		std::string getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExeGrade() const;
		bool beSign(Bureaucrat &bureaucrat);

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
		const int signGrade;
		const int exeGrade;
		bool sign;
};

std::ostream &operator<<(std::ostream &os, const Form &form);