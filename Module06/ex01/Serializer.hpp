/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:33:27 by cofische          #+#    #+#             */
/*   Updated: 2025/01/28 11:17:16 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#include <string>
#include "Data.hpp"
#include "../Colors.hpp"

class Serializer {
	public: 
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
		
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
};