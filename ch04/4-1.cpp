/*
exercise 4-1. Write a program that prompts for two integers to be entered and then uses an
if-else statement to output a message that states whether the integers are the same.
*/

#include <iostream>

int main (int argc, char *argv[]) {
    int value1;
    int value2;

    std::cout << "Enter two integers: ";
    std::cin >> value1 >> value2;

    if (value1 == value2) {
        std::cout << "The two values are the same\n";
    }
    else {
        std::cout << "The two values are NOT the same\n";
    }

    // Using a conditional operator
    value1 == value2 ?
        std::cout << "The two values are the same!\n" :
        std::cout << "The two values are NOT the same!\n";

    return 0;
}
