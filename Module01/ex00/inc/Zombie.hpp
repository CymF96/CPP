/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:14:44 by cofische          #+#    #+#             */
/*   Updated: 2025/01/08 17:43:10 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "../../Colors.hpp"

class Zombie {
	public:
		Zombie(const std::string &inputName);
		~Zombie();
		void announce(void);

	private:
		std::string	name;
};

Zombie *newZombie(const std::string &name);
void randomChump(const std::string &name);
