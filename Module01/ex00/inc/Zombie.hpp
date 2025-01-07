/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:14:44 by cofische          #+#    #+#             */
/*   Updated: 2025/01/07 12:04:19 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

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
