/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:05:10 by cofische          #+#    #+#             */
/*   Updated: 2025/01/22 11:35:58 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &inputName, const int &inputGrade) : name(inputName) {
	std::cout << "Bureaucrat has been hired" <<std::endl;
	if (inputGrade > 150)
		throw GradeTooLowException();
	else if (inputGrade < 1 )
		throw GradeTooHighException();
	else
		grade = inputGrade;
}
Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat has been fired" <<std::endl;
};
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
	std::cout << "Bureaucrat copy constructor called" <<std::endl;
};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat copy assignment called" <<std::endl;
	if (this != &other) {
		grade = other.grade;
	}
	return *this;
};

std::string Bureaucrat::getName() const {
	return name;
};

int Bureaucrat::getGrade() const {
	return grade;
};

void Bureaucrat::signForm(AForm &form) {
	if (form.beSign(*this))
		std::cout << BOLD BLUE << this->getName() << RESET << " signed " << BOLD BLUE << form.getName() << RESET << std::endl;
	else 
		std::cout << BOLD BLUE << this->getName() << RESET << " couldn't sign " << BOLD BLUE << form.getName() << RESET << " because " << BOLD RED << " their grade is too low" << RESET << std::endl;
};

void Bureaucrat::executeForm(AForm const &form) {
	if (form.execute(*this))
		std::cout << BOLD BLUE << this->getName() << RESET << " executed " << BOLD BLUE << form.getName() << RESET << std::endl;
	else 
		std::cout << BOLD BLUE << this->getName() << RESET << " couldn't execute " << BOLD BLUE << form.getName() << RESET << " because " << BOLD RED << " their grade is too low" << RESET << std::endl;
};

void Bureaucrat::incrementGrade(const int &inputGrade) {
	int tempGrade = getGrade();
	tempGrade += inputGrade;
	if (tempGrade > 150)
		throw GradeTooLowException();
	else
		grade = tempGrade;
};

void Bureaucrat::decrementGrade(const int &inputGrade) {
	int tempGrade = getGrade();
	tempGrade -= inputGrade;
	if (tempGrade < 1 )
		throw GradeTooHighException();
	else
		grade = tempGrade;
}; 

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return BOLD RED "Bureaucrat has a grade too low!\n" RESET;
};

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return BOLD RED "Bureaucrat has a grade too high!\n" RESET;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << BOLD BLUE << bureaucrat.getName() << RESET << ", bureaucrat grade " << BOLD RED << bureaucrat.getGrade() << RESET << std::endl;
	return os;
};