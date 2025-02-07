/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:56:48 by cofische          #+#    #+#             */
/*   Updated: 2025/02/07 17:32:34 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

stack inputElements;

/*******************************/
/****PRIVATE CONSTRUCTORS*******/
/*******************************/

RPN::RPN() {};
RPN::~RPN() {}
RPN::RPN(const RPN &other) { (void)other; }
RPN &RPN::operator=(const RPN &other) { (void)other; return *this; }

/*******************************/
/**********METHODS**************/
/*******************************/

void RPN::operation(std::string &input) {
	typeIt it = input.begin();
	int result = 0;
	for (; it != input.end(); ++it) {
		if (!isdigit(*it)) {
			result = calculation(*it);
			inputElements.push(result);
		} else {
			int temp = *it - '0';
			inputElements.push(temp);
		}
	}
	std::cout << BOLD BLUE << result << RESET << std::endl;
};

int RPN::calculation(char id) {
	int num1 = inputElements.top();
	inputElements.pop();
	int num2 = inputElements.top();
	inputElements.pop();
	switch (id) {
		case '+':
			return num2 + num1;
		case '-':
			return num2 - num1; 
		case '/':
			if (num1 == 0)
				throw std::runtime_error("Division by zero\n");
			return num2 / num1; ;
		case '*':
			return num2 * num1;
		default:
			throw std::invalid_argument("Invalid operator");
			break;
	}
};

/*******************************/
/*******HELPER FUNCTIONS********/
/*******************************/

void removeSpace(std::string &input) {
	typeIt it = input.begin();
	if (*it == ' ')
		return ;
	for (; it != input.end(); ++it) {
		if (*it == ' ')
			input.erase(it);
		if (it == input.end())
			return ;
	}
}

void checkInput(std::string &input){
	std::string checkArray = " 0123456789+-*/";
	typeIt it = input.begin();
	int digit = 0;
	int ope = 0;
	if (input.size() < 3)
		throw std::invalid_argument("invalid RPN format. Calcul impossible");
	if (!isdigit(input[0]) && !isdigit(input[1]))
		throw std::invalid_argument("invalid RPN format for 1st elements");
	for ( ; it != input.end(); ++it) {
		if (checkArray.find(*it) == std::string::npos) {
			throw std::invalid_argument("invalid RPN format. Input not recognize");
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
			ope++;
		else if (isdigit(*it))
			digit++;
	}
	if (ope != (digit - 1)) {
		throw std::invalid_argument("invalid RPN format. Calcul is impossible");
	}
};