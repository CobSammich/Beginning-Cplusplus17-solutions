/*
exercise 6-3. Write a program that reads an array size from the keyboard and
dynamically allocates an array of that size to hold floating-point values. Using pointer
notation, initialize all the elements of the array so that the value of the element at
index position n is 1 / (n + 1)2. Calculate the sum of the elements using array notation,
multiply the sum by 6, and output the square root of that result.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

int main (int argc, char *argv[]) {
    //const int NUM_WIDTH = 4;    // number of columns to print value to

    int array_size;
    std::cout << "Enter the size of the array: ";
    std::cin >> array_size;

    // dynamically allocate array
    float* values = new float[array_size] {};

    // fill with 1 / (n + 1)^2
    for (int n = 0; n < array_size; ++n)
        *(values + n) = 1.0 / std::pow(n + 1.0, 2.0);

    float sum = 0.0;
    for (int i = 0; i < array_size; ++i)
        sum += *(values + i);

    float finalValue = std::pow(sum * 6, 0.5);
    std::cout << "Final Value: " << finalValue << std::endl;
}
