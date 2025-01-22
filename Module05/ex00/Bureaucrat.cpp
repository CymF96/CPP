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

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &inputName, const int &inputGrade) : name(inputName) {
	std::cout << "Bureaucrat constructor called" <<std::endl;
	if (inputGrade > 150)
		throw GradeTooLowException();
	else if (inputGrade < 1 )
		throw GradeTooHighException();
	else
		grade = inputGrade;
}
Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" <<std::endl;
};
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
	std::cout << "Bureaucrat copy constructor called" <<std::endl;
};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat copy assignment called" <<std::endl;
	if (this != &other) {
		name = other.name;
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

void Bureaucrat::setName(const std::string &inputName) {
	name = inputName;
};

void Bureaucrat::incrementGrade(const int &inputGrade) {
	int tempGrade = getGrade();
	tempGrade += inputGrade;
	if (tempGrade > 1)
		throw GradeTooHighException();
	else
		grade = tempGrade;
};

void Bureaucrat::decrementGrade(const int &inputGrade) {
	int tempGrade = getGrade();
	tempGrade -= inputGrade;
	if (tempGrade > 150 )
		throw GradeTooLowException();
	else
		grade = tempGrade;
}; 

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return BOLD RED "Grade too low!" RESET " The lowest grade is 150.";
};

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return BOLD RED "Grade too high!" RESET " The highest grade is 1.";
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << BOLD BLUE << bureaucrat.getName() << RESET << ", bureaucrat grade " << BOLD RED << bureaucrat.getGrade() << RESET << std::endl;
	return os;
};