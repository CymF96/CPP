/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:35:45 by cofische          #+#    #+#             */
/*   Updated: 2025/01/15 16:28:21 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string.h>
#include "../../Colors.hpp"
#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		~Cure();
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);	
};