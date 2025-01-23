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

RobotomyRequestForm::RobotomyRequestForm(const std::string &inputTarget) : AForm("RobotomyRequestForm", 72, 45), target(inputTarget) {};
RobotomyRequestForm::~RobotomyRequestForm() {};
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {};
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
};

bool RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (this->getSign() && (executor.getGrade() <= this->getExeGrade())) {
		std::cout << "🛠️ Brrrrrrrrrrrrrr 🛠️\n";
		std::srand(std::time(0));
		int	success = (std::rand() % 100) + 1;
		(void)executor;
		if (success < 50)
			std::cout << this->target << " has been robotomized successfully" << std::endl;
		else
			std::cout << this->target << "'s robotomization failed" << std::endl;
		return true;
	} else
		throw AForm::GradeTooLowException();
};