/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:37:09 by cofische          #+#    #+#             */
/*   Updated: 2025/01/08 17:54:06 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "../../Colors.hpp"
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