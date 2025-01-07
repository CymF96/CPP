/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:14:44 by cofische          #+#    #+#             */
/*   Updated: 2025/01/07 13:02:09 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie {
	public:
		Zombie();
		~Zombie();
		void announce(void);
		void setName(std::string &inputName);

	private:
		std::string	name;
};

Zombie *zombieHorde(int N, std::string name);
