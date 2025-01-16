/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:37:09 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 17:28:15 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "../../Colors.hpp"
#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(const std::string &inputName, Weapon &inputWeapon);
		~HumanA();
		void attack();
		void setWeapon(Weapon &inputWeapon);

	private:
		std::string name;
		Weapon &weapon;
};