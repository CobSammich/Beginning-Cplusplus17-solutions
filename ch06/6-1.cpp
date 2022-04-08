/*
exercise 6-1. Write a program that declares and initializes an array with the first 50 odd
(as in not even) numbers. output the numbers from the array ten to a line using pointer
notation and then output them in reverse order, also using pointer notation.
*/

#include <iostream>
#include <iomanip>
#include <array>

int main (int argc, char *argv[]) {
    const int ARRAY_SIZE = 50;
    const int NUM_WIDTH = 4;    // number of columns to print value to

    // initialize the values to zero
    int oddNums[ARRAY_SIZE] = {};

    for (int i = 0; i < ARRAY_SIZE; ++i)
        oddNums[i] = 2 * i + 1;

    // pointer to the fist element of oddNums
    // output the numbers
    int* pOddNums = &oddNums[0];

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        // get current value using pointer notation
        int currVal = *(pOddNums + i);
        std::cout << std::setw(NUM_WIDTH) << currVal;

        // reset the line counter -- recycled from 5-6
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    // now print them in the reverse order
    for (int i = ARRAY_SIZE - 1; i >= 0; --i) {
        // get current value using pointer notation
        int currVal = *(pOddNums + i);
        std::cout << std::setw(NUM_WIDTH) << currVal;

        // reset the line counter -- recycled from 5-6
        if (i % 10 == 0) {
            std::cout << std::endl;
        }
    }

}
