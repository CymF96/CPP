/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:10:23 by cofische          #+#    #+#             */
/*   Updated: 2025/01/08 17:55:19 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../../Colors.hpp"

class Harl {
	public:
		Harl();
		~Harl();
		void complain(const std::string &level);
	
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void switchOff(void);
};

