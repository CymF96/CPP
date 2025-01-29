/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-29 16:14:21 by cofische          #+#    #+#             */
/*   Updated: 2025-01-29 16:14:21 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Array.hpp"
#define MAX_VAL 750

int main(int, char**)
{
    Array<float> floatArray(5);
    Array<double> doubleArray(0);
    Array<int> numbers(MAX_VAL);

    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 100;
        numbers[i] = value;
        mirror[i] = value;
    }

    float flt = 0.5;
    for (int i = 0; i < 5; i++)
        floatArray[i] = flt += 1.5;

    std::cout << BOLD "\nFLOAT ARRAY" RESET << std::endl;
    std::cout << floatArray << std::endl;
    std::cout << BOLD "Double ARRAY" RESET << std::endl;
    std::cout << doubleArray << std::endl;
    std::cout << BOLD "INT \"NUMBERS\" ARRAY" RESET << std::endl;
    std::cout << numbers << std::endl;
    std::cout << BOLD "INT \"MIRROR\" ARRAY" RESET << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << "Array[" << i << "] = " << mirror[i] << std::endl;

    std::cout << BOLD "\n***TESTING COPY VALUE IN ARRAY***" RESET << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
        else if (i < 5)
            std::cout << "mirror[" << i << "] = " << mirror[i] << " // numbers[" << i << "] = " << numbers[i] << std::endl;
    }
    
    {
        std::cout << BOLD "\n***TESTING CONSTRUCTORS***" RESET << std::endl;
        Array<int> assignNumbers = numbers;
        Array<int> copyNumbers(numbers);
        std::cout << BOLD "\n***TESTING DEEP COPY VALUE IN ANOTHER SCOPE***" RESET << std::endl;
        {
            for (int i = 0; i < MAX_VAL; i++)
                numbers[i] = rand() % 1000;
            for (int i = 0; i < 5; i++) {
                std::cout << "assignNumbers[" << i << "] = " << assignNumbers[i] << " // numbers[" << i << "] = " << numbers[i] << std::endl;
                std::cout << "copyNumbers[" << i << "] = " << copyNumbers[i] << " // numbers[" << i << "] = " << numbers[i] << std::endl;
            }
        }
    }

    std::cout << BOLD "\n***TESTING OUT OF RANGE OPERATOR***" RESET << std::endl;
    try {
        std::cout << "numbers[-2] = " << numbers[-2] << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    } try {
        std::cout << "numbers[MAX_VAL] = " << numbers[MAX_VAL] << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    } try {
        std::cout << "numbers[140] = " << numbers[140] << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << BOLD "\n***TRYING TIP FROM SUBJECT -- RAW POINTER -- ***" RESET << std::endl;
    {
        int* a = new int();
        std::cout << "Value pointed by 'a': " << *a << std::endl;
        delete a;
    }
    std::cout << std::endl;

    delete [] mirror;
    
    return 0;
}