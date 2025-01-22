/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 16:00:06 by cofische          #+#    #+#             */
/*   Updated: 2025-01-22 16:00:06 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string &inputTarget) : AForm("PresidentialPardonForm", 72, 45), target(inputTarget) {};
RobotomyRequestForm::~RobotomyRequestForm() {};
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {};
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
};

bool RobotomyRequestForm::beSign(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() >= this->getSignGrade())
		throw Bureaucrat::GradeTooLowException();
	else
		this->setSign();
	return (this->getSign());
};

bool RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (this->getSign() && (executor.getGrade() <= this->getExeGrade())) {
		int	success;
		srand((unsigned) time(NULL));
		success = rand() % 2;
		(void)executor;
		if (success)
			std::cout << this->target << " has been robotomized successfully" << std::endl;
		else
			std::cout << this->target << "'s robotomization failed" << std::endl;
		return true;
	} else
		throw Bureaucrat::GradeTooLowException();
};