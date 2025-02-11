/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:49:11 by cofische          #+#    #+#             */
/*   Updated: 2025/02/11 09:49:13 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

size_t getSize(char** arr) {
    size_t count = 0;
    while (arr[count]) {
        count++;
    }
    return count;
}

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << BOLD RED "Format error: " RESET "./PmergeMe 1 2 3" << std::endl;
        return -1;
    }
    size_t size = getSize(av);
    Pmerge::sorted(av, size);
    return 0;
}