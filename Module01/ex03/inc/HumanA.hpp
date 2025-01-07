/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:37:09 by cofische          #+#    #+#             */
/*   Updated: 2025/01/07 16:13:41 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(const std::string &inputName, const Weapon &inputWeapon);
		~HumanA();
		void attack();	

	
	private:
		std::string name;
		Weapon weapon;
};