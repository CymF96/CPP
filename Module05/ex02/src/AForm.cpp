/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 12:43:09 by cofische          #+#    #+#             */
/*   Updated: 2025-01-22 12:43:09 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm(const std::string &inputName, const int &inputSignGrade, const int &inputExeGrade) : 
	name(inputName), signGrade(inputSignGrade), exeGrade(inputExeGrade), sign(false) {
	std::cout << "AForm constructor called" << std::endl;
	if (signGrade < 1 || exeGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || exeGrade > 150)
		throw GradeTooLowException();
};

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
};

AForm::AForm(const AForm &other) : 
	name(other.name), signGrade(other.signGrade), exeGrade(other.exeGrade), sign(other.sign) {
	std::cout << "AForm copy constructor called" << std::endl;
};

AForm &AForm::operator=(const AForm &other) {
	std::cout << "AForm copy assignment called" << std::endl;
	if (this != &other) {
		sign = other.sign;
	}
	return *this;
};

std::string AForm::getName() const {
	return name;
};

bool AForm::getSign() const {
	return sign;
};

int AForm::getSignGrade() const {
	return signGrade;
};

int AForm::getExeGrade() const {
	return exeGrade;
};

void AForm::setSign() {
	sign = true;
}

bool AForm::beSign(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() >= this->getSignGrade())
		throw Bureaucrat::GradeTooLowException();
	else
		this->sign = true;
	return (this->getSign());
};

const char *AForm::GradeTooLowException::what() const throw() {
	return BOLD RED "AForm has a grade too low!" RESET " The lowest grade is 150.";
};

const char *AForm::GradeTooHighException::what() const throw() {
	return BOLD RED "AForm has a grade too high!" RESET " The highest grade is 1.";
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
	os << "The AForm " << BOLD BLUE << AForm.getName() << RESET << " needs the following requirement:\nCan be signed by bureaucrat with grade: " << BOLD MAGENTA << AForm.getSignGrade()
		<< RESET << " or higher.\nCan be executed by bureaucrat with grade: " << BOLD MAGENTA << AForm.getExeGrade() << RESET << " or higher.\nStatus of AForm " << BOLD BLUE << AForm.getName() << RESET << ": ";
	if (AForm.getSign())
		os << BOLD GREEN << "signed" << RESET << std::endl;
	else
		os << BOLD RED << "not signed" << RESET << std::endl;
	
	return os;
};