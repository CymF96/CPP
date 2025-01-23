/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 16:00:31 by cofische          #+#    #+#             */
/*   Updated: 2025-01-22 16:00:31 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &inputTarget) : AForm("PresidentialPardonForm", 25, 5), target(inputTarget) {};
PresidentialPardonForm::~PresidentialPardonForm() {};
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {};
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
};

bool PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (this->getSign() && (executor.getGrade() <= this->getExeGrade())) {
		std::cout << "Dear " << BOLD BLUE << this->target << RESET << ",\nYou have been pardonned by " << BOLD CYAN << "Zaphod Beeblebrox" << std::endl;
		return true;
	} else
		throw AForm::GradeTooLowException();
};