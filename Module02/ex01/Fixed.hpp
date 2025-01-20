/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:51:02 by cofische          #+#    #+#             */
/*   Updated: 2025/01/20 11:55:24 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "../Colors.hpp"

class Fixed {
	 
	public:
		Fixed();
		Fixed(const int &a);
		Fixed(const float &a);
		~Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);

		int getRawBits(void) const;
		void setRawBits(int const &raw);
		float toFloat(void) const;
		int toInt(void) const;
		
	private:
		int fp;
		static const int fb = 8;
		
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

