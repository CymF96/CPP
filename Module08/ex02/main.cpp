/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:06:02 by cofische          #+#    #+#             */
/*   Updated: 2025/02/03 19:18:18 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {
	std::cout << INVERSE BOLD"===== Testing MutantStack =====\n" RESET;

	// Create a MutantStack of integers
	MutantStack<int> mstack;
	
	/**********************************/
	/******TEST OF STACK FUNCTION******/
	/**********************************/
	std::cout << UNDERLINE "\nPushing elements: " RESET "5, 17\n";
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " BOLD BLUE << mstack.top() << RESET "\n";
	std::cout << "New top element: " BOLD BLUE << mstack.top() << RESET "\n";
	std::cout << "Stack size: " BOLD BLUE << mstack.size() << RESET "\n";
	std::cout << UNDERLINE "\nPushing more elements: " RESET "3, 5, 737, 0\n";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "New top element: " BOLD BLUE << mstack.top() << RESET "\n";
	std::cout << "Stack size: " BOLD BLUE << mstack.size() << RESET "\n";
	std::cout << UNDERLINE "\nPopping the top element...\n" RESET;
	mstack.pop();
	mstack.pop();
	mstack.pop();
	mstack.pop();
	std::cout << "New top element (should be the same as initial -- 17): " BOLD BLUE << mstack.top() << RESET "\n";
	std::cout << "Stack size (should be the same as initial -- 2): " BOLD BLUE << mstack.size() << RESET "\n";
	
	/**********************************/
	/******TEST OF ITERATORS **********/
	/**********************************/
	std::cout << UNDERLINE "\nIterating through the MutantStack:\n" RESET;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << "\n";

	/**********************************/
	/******TEST OF CONSTRUCTORS********/
	/**********************************/
	std::cout << UNDERLINE "\nCopying MutantStack to another instance...\n" RESET;
	MutantStack<int> mstack_copy(mstack);
	std::cout << UNDERLINE "Assigning MutantStack to another instance...\n" RESET;
	MutantStack<int> mstack_assign;
	mstack_assign = mstack;

	// 
	std::cout << INVERSE BOLD "\nVerify copied and assigned stacks have same elements" RESET UNDERLINE"\n\nIterating through the copied MutantStack:\n" RESET;
	for (MutantStack<int>::iterator it = mstack_copy.begin(); it != mstack_copy.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";

	std::cout << UNDERLINE "\nIterating through the assigned MutantStack:\n" RESET;
	for (MutantStack<int>::iterator it = mstack_assign.begin(); it != mstack_assign.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";

	/**********************************/
	/***TEST OF STACK COMPATIBILITY****/
	/**********************************/
	std::cout << UNDERLINE "\nCopying MutantStack into std::stack...\n" RESET;
	std::stack<int> s(mstack);
	std::cout << "Top of std::stack: " << s.top() << "\n\n";

	return 0;
}



// int main() {
// 	MutantStack<int> mstack;
	
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
	
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
	
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
	
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
	
// 	++it;
// 	--it;
// 	while (it != ite) {
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
	
// 	std::stack<int> s(mstack);
	
// 	return 0;
// }