/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:28:14 by cofische          #+#    #+#             */
/*   Updated: 2025/01/07 16:13:49 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Weapon {
	public:
		Weapon(const std::string &inputWeapon);
		~Weapon();
		const std::string getType(void);
		void setType(const std::string &inputType);
	
	private:
		std::string type;

};