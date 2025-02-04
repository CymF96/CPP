/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:12:16 by cofische          #+#    #+#             */
/*   Updated: 2025/02/03 10:47:32 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}

// class Awesome
// {
//   public:
//     Awesome(void) : _n(0) {}
//     Awesome( int n ) : _n( n ) {}
//     Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
//     bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
//     bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
//     bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
//     bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
//     bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
//     bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
//     int get_n() const { return _n; }
//   private:
//     int _n;
// };
// std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

// int main(void)
// {
// 	Awesome a(2), b(4);

//         swap(a, b);
//         std::cout << a << " " << b << std::endl;
//         std::cout << max(a, b) << std::endl;
//         std::cout << min(a, b) << std::endl;
//         return (0);
// }

// int main() {

// 	int num1 = 5, num2 = 10;
// 	double doub1 = 2.5, doub2 = -42.6;
// 	float flo1 = 45.32f, flo2 = -89.54f;
// 	char a = 'a', b = 'a';
	
// 	std::cout << BOLD << "-- SWAP -- \n" RESET;
// 	std::cout << "num1: " BOLD BLUE << num1 << RESET ", num2: " BOLD BLUE << num2 << RESET "\n"; 
// 	swap(num1, num2); 
// 	std::cout << "new num1: " BOLD CYAN << num1 << RESET ", new num2: " BOLD CYAN << num2 << RESET << std::endl;
// 	std::cout << "\ndoub1: " BOLD BLUE << doub1 << RESET ", doub2: " BOLD BLUE << doub2 << RESET "\n"; 
// 	swap(doub1, doub2); 
// 	std::cout << "new doub1: " BOLD CYAN << doub1 << RESET ", new doub2: " BOLD CYAN << doub2 << RESET << std::endl;
// 	std::cout << "\nflo1: " BOLD BLUE << flo1 << RESET ", flo2: " BOLD BLUE << flo2 << RESET "\n"; 
// 	swap(flo1, flo2); 
// 	std::cout << "new flo1: " BOLD CYAN << flo1 << RESET ", new flo2: " BOLD CYAN << flo2 << RESET << std::endl;
// 	std::cout << "\na: " BOLD BLUE << a << RESET ", b: " BOLD BLUE << b << RESET "\n"; 
// 	swap(a, b); 
// 	std::cout << "new a: " BOLD CYAN << a << RESET ", new b: " BOLD CYAN << b << RESET << std::endl;
	
// 	std::cout << BOLD << "\n-- MAX -- \n" RESET;
// 	std::cout << "num1: " BOLD BLUE << num1 << RESET ", num2: " BOLD BLUE << num2 << RESET "\n"; 
// 	std::cout << "result: " BOLD CYAN << max(num1, num2) << RESET << std::endl;
// 	std::cout << "\ndoub1: " BOLD BLUE << doub1 << RESET ", doub2: " BOLD BLUE << doub2 << RESET "\n"; 
// 	std::cout << "result: " BOLD CYAN << max(doub1, doub2) << RESET << std::endl;
// 	std::cout << "\nflo1: " BOLD BLUE << flo1 << RESET ", flo2: " BOLD BLUE << flo2 << RESET "\n"; 
// 	std::cout << "result: " BOLD CYAN << max(flo1, flo2) << RESET << std::endl;
// 	std::cout << "\na: " BOLD BLUE << a << RESET ", b: " BOLD BLUE << b << RESET "\n"; 
// 	std::cout << "result: " BOLD CYAN << max(a, b) << RESET << std::endl;

// 	std::cout << BOLD << "\n-- MIN -- \n" RESET;
// 	std::cout << "num1: " BOLD BLUE << num1 << RESET ", num2: " BOLD BLUE << num2 << RESET "\n"; 
// 	std::cout << "result: " BOLD CYAN << min(num1, num2) << RESET << std::endl;
// 	std::cout << "\ndoub1: " BOLD BLUE << doub1 << RESET ", doub2: " BOLD BLUE << doub2 << RESET "\n"; 
// 	std::cout << "result: " BOLD CYAN << min(doub1, doub2) << RESET << std::endl;
// 	std::cout << "\nflo1: " BOLD BLUE << flo1 << RESET ", flo2: " BOLD BLUE << flo2 << RESET "\n"; 
// 	std::cout << "result: " BOLD CYAN << min(flo1, flo2) << RESET << std::endl;
// 	std::cout << "\na: " BOLD BLUE << a << RESET ", b: " BOLD BLUE << b << RESET "\n"; 
// 	std::cout << "result: " BOLD CYAN << min(a, b) << RESET << std::endl;
	
// 	return 0;
// }