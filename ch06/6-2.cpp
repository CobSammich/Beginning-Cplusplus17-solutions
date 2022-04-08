/*
exercise 6-2. revisit the previous exercise, but instead of accessing the array values
using the loop counter, this time you should employ pointer increments (using the
++ operator) to traverse the array when outputting it for the first time. after that, use
pointer decrements (using --) to traverse the array again in the reverse direction.
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
        // Increment the pointer to the next value
        // kinda similar to an iterator...
        std::cout << std::setw(NUM_WIDTH) << *(pOddNums++);
        // reset the line counter -- recycled from 5-6
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    // NOTE: decrement before here so we come back to the last element in the array
    // now print them in the reverse order
    for (int i = ARRAY_SIZE - 1; i >= 0; --i) {
        // get current value using pointer notation
        std::cout << std::setw(NUM_WIDTH) << *(--pOddNums);

        // reset the line counter -- recycled from 5-6
        if (i % 10 == 0) {
            std::cout << std::endl;
        }
    }

}
