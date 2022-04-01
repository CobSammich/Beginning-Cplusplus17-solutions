/*
exercise 5-1. Write a program that outputs the squares of the odd integers from 1 up to a limit that
is entered by the user.
*/

#include <cmath>
#include <iostream>

int main (int argc, char *argv[])
{
    int value;
    std::cout << "This will compute the squares of the odd integers from 1 to a given upper bound.\n";
    std::cout << "Enter the upper bound as an integer: ";
    std::cin >> value;

    for (size_t i = 1; i < value; i++) {
        // if i is odd
        if (i % 2 == 1) {
            int square = std::pow(i, 2);
            printf("Square of %lu is %d\n", i, square);
        }
    }

    return 0;
}
