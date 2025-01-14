/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:49:04 by cofische          #+#    #+#             */
/*   Updated: 2025/01/14 12:52:26 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "../../Colors.hpp"
#include "Claptrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(const std::string &inputName);
		~FragTrap();
		void highFivesGuys(void);
};