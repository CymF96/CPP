/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:12:23 by cofische          #+#    #+#             */
/*   Updated: 2025/02/07 17:31:02 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stack>
#include "../Colors.hpp"

typedef std::stack<int> stack;
typedef std::string::iterator typeIt;

class RPN {
	public:
		static void operation(std::string &input);
		static int calculation(char id); 
		
	private:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
};

void checkInput(std::string &input);
void removeSpace(std::string &input);


