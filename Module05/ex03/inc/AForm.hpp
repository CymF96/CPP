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

class AForm {
	public:
		AForm(const std::string &inputName, const int &inputSignGrade, const int &inputExeGrade);
		virtual ~AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);

		std::string getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExeGrade() const;
		void setSign();
		bool beSign(Bureaucrat &bureaucrat);
		virtual bool execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char *what() const throw();
				virtual const char *what2() const throw();
				virtual const char *what3() const throw();
		};
	
	private:
		const std::string name;
		const int signGrade;
		const int exeGrade;
		bool sign;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);