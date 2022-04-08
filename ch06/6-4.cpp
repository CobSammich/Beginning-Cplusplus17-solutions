/*
exercise 6-4. repeat the calculation in exercise 6-3 but using a vector<> container
allocated in the free store. test the program with more than 100,000 elements. do you
notice anything interesting about the result?

Answer: The calculation of 1 / (n + 1)^2 converges to ~3.14139 (approximation of pi) with > 100,000
elements

*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

int main (int argc, char *argv[]) {
    //const int NUM_WIDTH = 4;    // number of columns to print value to

    int array_size;
    std::cout << "Enter the size of the array: ";
    std::cin >> array_size;

    auto* values = new std::vector<float> {};

    // fill with 1 / (n + 1)^2
    for (int n = 0; n < array_size; ++n)
        values->push_back(1.0 / std::pow(n + 1.0, 2.0));

    // sum values in array
    float sum = 0.0;
    for (int i = 0; i < array_size; ++i)
        sum += values->at(i);

    float finalValue = std::pow(sum * 6, 0.5);
    std::cout << "Final Value: " << finalValue << std::endl;

    // free memory
    delete values;
}
