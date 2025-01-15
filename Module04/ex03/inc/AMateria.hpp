/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:28:17 by cofische          #+#    #+#             */
/*   Updated: 2025/01/15 16:33:03 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string.h>
#include "../../Colors.hpp"
#include "ICharacter.hpp"

class AMateria {
	protected:
		std::string type;

	public:
		AMateria(std::string const &inputType);
		~AMateria();
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};