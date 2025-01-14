/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:52:42 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 13:58:44 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Claptrap.hpp"
#include "../../Colors.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(const std::string &inputName);
		~ScavTrap();
		void guardGate();
};