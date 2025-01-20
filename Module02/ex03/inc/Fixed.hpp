/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:51:02 by cofische          #+#    #+#             */
/*   Updated: 2025/01/20 11:58:56 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>
#include "../../Colors.hpp"
 
class Fixed {
	 
	public:
		Fixed();
		Fixed(const int &a);
		Fixed(const float &a);
		~Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		
		bool operator<(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);

		int getRawBits(void) const;
		void setRawBits(int const &raw);
		float toFloat(void) const;
		int toInt(void) const;
		void setFromFloat(float &f_nb);		
		static Fixed &min(Fixed &x, Fixed &y);
		static Fixed &max(Fixed &x, Fixed &y);
		static const Fixed &min(const Fixed &x, const Fixed &y);
		static const Fixed &max(const Fixed &x, const Fixed &y);
		
	private:
		int fp;
		static const int fb = 8;
		
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
std::istream& operator>>(std::istream& is, Fixed& fixed);
