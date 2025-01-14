/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:10:54 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 12:38:08 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "../../Colors.hpp"

class ClapTrap {
	public:
	ClapTrap(const std::string &inputName);
	~ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	
	void attack(const std::string &target);
	void takeDamage(unsigned int &amount);
	void beRepaired(unsigned int &amount);
	std::string getName();
	unsigned int getHitPoints();
	unsigned int getEnergyPoints();
	unsigned int getAttackDamage();
	void setEnergyPoints(const unsigned int &inputEnergyPoints);
	void setHitPoints(const unsigned int &inputHitPoints);
	void setAttackDamage(const unsigned int &inputAttackDamage);

	private:
		std::string name;
		unsigned int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;
		
};

void defineClapTrapper(ClapTrap &inputClapTrapper);