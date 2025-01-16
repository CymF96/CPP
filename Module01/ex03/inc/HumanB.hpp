/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:35:51 by cofische          #+#    #+#             */
/*   Updated: 2025/01/16 17:45:28 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "../../Colors.hpp"
#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(const std::string &inputName);
		~HumanB();
		void attack();
		void setWeapon(Weapon &inputWeapon);
	
	private:
		Weapon *weapon;
		std::string name; 	
};
