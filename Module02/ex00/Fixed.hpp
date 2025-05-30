/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:51:02 by cofische          #+#    #+#             */
/*   Updated: 2025/01/20 11:32:16 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../Colors.hpp"

class Fixed {
	
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);

		int getRawBits(void) const;
		void setRawBits(int const &raw);
		
	private:
		int fp;
		static const int fb = 8;
		
};