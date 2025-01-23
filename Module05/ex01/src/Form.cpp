/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 12:43:09 by cofische          #+#    #+#             */
/*   Updated: 2025-01-22 12:43:09 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form(const std::string &inputName, const int &inputSignGrade, const int &inputExeGrade) : 
	name(inputName), signGrade(inputSignGrade), exeGrade(inputExeGrade), sign(false) {
	// std::cout << "Form constructor called" << std::endl;
	if (signGrade < 1 || exeGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || exeGrade > 150)
		throw GradeTooLowException();
};

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
};

Form::Form(const Form &other) : 
	name(other.name), signGrade(other.signGrade), exeGrade(other.exeGrade), sign(other.sign) {
	std::cout << "Form copy constructor called" << std::endl;
};

Form &Form::operator=(const Form &other) {
	std::cout << "Form copy assignment called" << std::endl;
	if (this != &other) {
		sign = other.sign;
	}
	return *this;
};

std::string Form::getName() const {
	return name;
};

bool Form::getSign() const {
	return sign;
};

int Form::getSignGrade() const {
	return signGrade;
};

int Form::getExeGrade() const {
	return exeGrade;
};

bool Form::beSign(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() >= this->getSignGrade())
		throw GradeTooLowException();
	else
		this->sign = true;
	return (this->getSign());
};

const char *Form::GradeTooLowException::what() const throw() {
	return BOLD RED "Form has a grade too low!" RESET " The lowest grade is 150.";
};

const char *Form::GradeTooLowException::what2() const throw() {
	return BOLD RED "their grade is too low!" RESET;
};

const char *Form::GradeTooHighException::what() const throw() {
	return BOLD RED "Form has a grade too high!" RESET " The highest grade is 1.";
};

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "The form " << BOLD BLUE << form.getName() << RESET << " has the following requirement:\nCan be signed by bureaucrat with grade " << BOLD MAGENTA << form.getSignGrade()
		<< RESET << " or higher.\nCan be executed by bureaucrat with grade " << BOLD MAGENTA << form.getExeGrade() << RESET << " or higher.\nStatus of form " << BOLD BLUE << form.getName() << RESET << ": ";
	if (form.getSign())
		os << BOLD GREEN << "signed" << RESET << std::endl;
	else
		os << BOLD RED << "not signed" << RESET << std::endl;
	
	return os;
};