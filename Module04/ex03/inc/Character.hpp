/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:43:12 by cofische          #+#    #+#             */
/*   Updated: 2025/01/15 16:45:16 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string.h>
#include "../../Colors.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class Character : public ICharacter {
	protected:
		AMateria iventory[4];
		

	public:
		Character(const std::string &inputName);
		~Character();
		Character(const Character &other);
		Character &operator=(const Character &other);
};