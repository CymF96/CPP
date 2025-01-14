/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:04:00 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 13:54:22 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../../Colors.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap(const std::string &inputName);
		~DiamondTrap();
		
		void whoAmI();
		void attack(const std::string &target);
	
	private:
		const std::string name;
};