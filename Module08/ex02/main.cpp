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
	std::cout << "===== Testing MutantStack =====\n" ;

	// Create a MutantStack of integers
	MutantStack<int> mstack;
	
	/**********************************/
	/******TEST OF STACK FUNCTION******/
	/**********************************/
	std::cout <<  "\nPushing elements: "  "5, 17\n";
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: "  << mstack.top() <<  "\n";
	std::cout << "New top element: "  << mstack.top() <<  "\n";
	std::cout << "Stack size: "  << mstack.size() <<  "\n";
	std::cout <<  "\nPushing more elements: "  "3, 5, 737, 0\n";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "New top element: "  << mstack.top() <<  "\n";
	std::cout << "Stack size: "  << mstack.size() <<  "\n";
	std::cout <<  "\nPopping the top element...\n" ;
	mstack.pop();
	mstack.pop();
	mstack.pop();
	mstack.pop();
	std::cout << "New top element (should be the same as initial -- 17): "  << mstack.top() <<  "\n";
	std::cout << "Stack size (should be the same as initial -- 2): "  << mstack.size() <<  "\n";
	
	/**********************************/
	/******TEST OF ITERATORS **********/
	/**********************************/
	std::cout <<  "\nIterating through the MutantStack:\n" ;
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
	std::cout <<  "\nCopying MutantStack to another instance...\n" ;
	MutantStack<int> mstack_copy(mstack);
	std::cout <<  "Assigning MutantStack to another instance...\n" ;
	MutantStack<int> mstack_assign;
	mstack_assign = mstack;

	// 
	std::cout <<  "\nVerify copied and assigned stacks have same elements"  "\n\nIterating through the copied MutantStack:\n" ;
	for (MutantStack<int>::iterator it = mstack_copy.begin(); it != mstack_copy.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";

	std::cout <<  "\nIterating through the assigned MutantStack:\n" ;
	for (MutantStack<int>::iterator it = mstack_assign.begin(); it != mstack_assign.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";

	return 0;
}

// #include <list>

// int main() {
// 	std::cout << "===== Testing MutantStack =====\n" ;

// 	// Create a std::list of integers
// 	std::list<int> mlist;
	
// 	/**********************************/
// 	/******TEST OF LIST FUNCTION******/
// 	/**********************************/
// 	std::cout <<  "\nPushing elements: "  "5, 17\n";
// 	mlist.push_back(5);
// 	mlist.push_back(17);
// 	std::cout << "Top element: "  << mlist.back() <<  "\n";
// 	std::cout << "New top element: "  << mlist.back() <<  "\n";
// 	std::cout << "Stack size: "  << mlist.size() <<  "\n";
// 	std::cout <<  "\nPushing more elements: "  "3, 5, 737, 0\n";
// 	mlist.push_back(3);
// 	mlist.push_back(5);
// 	mlist.push_back(737);
// 	mlist.push_back(0);
// 	std::cout << "New top element: "  << mlist.back() <<  "\n";
// 	std::cout << "Stack size: "  << mlist.size() <<  "\n";
// 	std::cout <<  "\nPopping the top element...\n" ;
// 	mlist.pop_back();
// 	mlist.pop_back();
// 	mlist.pop_back();
// 	mlist.pop_back();
// 	std::cout << "New top element (should be the same as initial -- 17): "  << mlist.back() <<  "\n";
// 	std::cout << "Stack size (should be the same as initial -- 2): "  << mlist.size() <<  "\n";
	
// 	/**********************************/
// 	/******TEST OF ITERATORS **********/
// 	/**********************************/
// 	std::cout <<  "\nIterating through the MutantStack:\n" ;
// 	std::list<int>::iterator it = mlist.begin();
// 	std::list<int>::iterator ite = mlist.end();
// 	while (it != ite) {
// 		std::cout << *it << " ";
// 		++it;
// 	}
// 	std::cout << "\n";

// 	/**********************************/
// 	/******TEST OF CONSTRUCTORS********/
// 	/**********************************/
// 	std::cout <<  "\nCopying MutantStack to another instance...\n" ;
// 	std::list<int> mlist_copy(mlist);
// 	std::cout <<  "Assigning MutantStack to another instance...\n" ;
// 	std::list<int> mlist_assign;
// 	mlist_assign = mlist;

// 	// 
// 	std::cout <<  "\nVerify copied and assigned stacks have same elements"  "\n\nIterating through the copied MutantStack:\n" ;
// 	for (std::list<int>::iterator it = mlist_copy.begin(); it != mlist_copy.end(); ++it)
// 		std::cout << *it << " ";
// 	std::cout << "\n";

// 	std::cout <<  "\nIterating through the assigned MutantStack:\n" ;
// 	for (std::list<int>::iterator it = mlist_assign.begin(); it != mlist_assign.end(); ++it)
// 		std::cout << *it << " ";
// 	std::cout << "\n";

// 	return 0;
// }



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