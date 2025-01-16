/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:14:44 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 16:49:58 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "../../Colors.hpp"

class Zombie {
	public:
		Zombie();
		~Zombie();
		void announce(void);
		void setName(const std::string &inputName);

	private:
		std::string	name;
};

Zombie *zombieHorde(int N, const std::string &name);
