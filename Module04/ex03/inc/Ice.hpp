/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:36:05 by cofische          #+#    #+#             */
/*   Updated: 2025/01/15 15:41:16 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string.h>
#include "../../Colors.hpp"
#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		~Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);	
};