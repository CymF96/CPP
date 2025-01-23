/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-23 10:44:34 by cofische          #+#    #+#             */
/*   Updated: 2025-01-23 10:44:34 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern() {
	std::cout << "Random Intern has been hired" << std::endl;
};
Intern::~Intern() {
	std::cout << "Random Intern has been fired" << std::endl;
};
Intern::Intern(const Intern &other) {(void)other;};
Intern &Intern::operator=(const Intern &other) {(void)other; return *this;};

const char* Intern::NoFormFound::what() const throw() {
	return BOLD RED "Technical problem " RESET "(You sure about that?)\n";
};

AForm *Intern::makeForm(const std::string &formName, const std::string &inputTarget) {
	std::string formNames[3] = {"Shrubbery", "Robotomy", "Presidential"};
	AForm *(*formCreation[3])(const std::string &) = {createShrubbery, createRobotomy, createPresidential};

	for (int i = 0; i < 3; i++) {
		if ((formNames[i]).find(formName) != std::string::npos) {
			std::cout << "Intern creates " << BOLD BLUE << (formNames[i] + "Form") << RESET << std::endl;
			return (formCreation[i])(inputTarget);
		}
	}
	throw NoFormFound();
	return (NULL);
};

AForm *createShrubbery(const std::string &target) {
	return new ShrubberyCreationForm(target);
};
AForm *createRobotomy(const std::string &target) {
	return new RobotomyRequestForm(target);
};
AForm *createPresidential(const std::string &target) {
	return new PresidentialPardonForm(target);
};

/*
----C++11 with std::function and vector use possible to lambda functions in funciton pointer array---------

AForm *Intern::makeForm(const std::string &formName, const std::string &inputTarget) {
	std::string formsName[3] = {"Shrubbery", "Robotomy", "Presidential"};
	AForm *(*formCreation[3])(const std::string &) = {
		[](const std::string &target) { return new ShrubberyCreationForm(target);},
		[](const std::string &target) { return new RobotomyRequestForm(target);},
		[](const std::string &target) { return new PresidentialPardonForm(target);}
	};

	for (int i = 0; i < 3; i++) {
		if ((formsName[i]).find(formName) != std::string::npos)
			return (formCreation[i])(inputTarget);
	}
	throw NoFormFound();
	return (NULL);
};
*/
